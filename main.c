/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Sun Apr 16 15:24:18 2017 theo champion
*/

#include "header.h"

inline static int	signal_status_handler(int wait_status)
{
  return ((WSTOPSIG(wait_status) == SIGTRAP
           || WSTOPSIG(wait_status) == SIGSTOP)
          && WIFSTOPPED(wait_status));
}

static int	attach_to_running_process(pid_t pid)
{
  if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
    {
      perror("Ptrace attach: ");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

static int	launch_child(int argc, char **argv,
                             char * const *env, char *path)
{
  char		*args[argc + 1];
  int		i;

  i = -1;
  while (++i < argc)
    args[i] = argv[i + 1];
  args[argc] = NULL;
  ptrace(PTRACE_TRACEME);
  kill(getpid(), SIGSTOP);
  if (execve(path, args, env) == -1)
    return (EXIT_FAILURE);
  free(path);
  return (EXIT_SUCCESS);
}

int				trace(pid_t pid)
{
  struct user_regs_struct	r;
  unsigned short		instr_code;
  int				wait_status;

  waitpid(pid, &wait_status, 0);
  while (signal_status_handler(wait_status))
    {
      if (ptrace(PTRACE_GETREGS, pid, NULL, &r))
        perror("ptrace");
      instr_code = ptrace(PTRACE_PEEKTEXT, pid, r.rip, NULL);
      if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
        perror("ptrace");
      waitpid(pid, &wait_status, 0);
      if (signal_status_handler(wait_status))
        {
          if (ptrace(PTRACE_GETREGS, pid, NULL, &r))
            perror("ptrace");
          if (instr_code == SYSCALL_CODE)
            print_syscall(pid, r.orig_rax, r.rax);
        }
    }
  return (wait_status);
}

int		main(int argc, char **av, char * const *env)
{
  pid_t		pid;
  int		exit_status;
  char		*path;

  if (argc < 2)
    return (fprintf(stderr, "Usage : %s [-s] [-p <pid>|<command>]\n", av[0])
            || 1);
  if (!strcmp(av[1], "-p") && av[2])
    {
      if (attach_to_running_process((pid = (pid_t)atoi(av[2]))))
        return (EXIT_FAILURE);
    }
  else
    {
      if ((path = getpath(av[1], env)) == NULL)
        return (fprintf(stderr, "No such file or directory %s\n", av[1]) || 1);
      pid = fork();
      if (pid == 0)
        return (launch_child(argc, av, env, path));
    }
  exit_status = trace(pid);
  if (WIFEXITED(exit_status))
    fprintf(stderr, "exit_group(0x%x) = ?\n+++ exited with %d +++\n",
            WEXITSTATUS(exit_status), WEXITSTATUS(exit_status));
  return (EXIT_SUCCESS);
}
