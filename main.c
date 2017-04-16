/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Sun Apr 16 18:51:45 2017 theo champion
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

static int	launch_child(int argc, char **argv, int mode)
{
  char		*args[argc + 1];
  int		i;

  i = -1;
  while (++i < argc)
    args[i] = argv[i + 1 + mode];
  args[i] = NULL;
  ptrace(PTRACE_TRACEME);
  kill(getpid(), SIGSTOP);
  if (execvp(argv[1 + mode], args) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

static int				trace(pid_t pid, int mode)
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
            print_syscall(pid, r.orig_rax, r.rax, mode);
        }
    }
  return (wait_status);
}

int		main(int argc, char **av)
{
  pid_t		pid;
  int		mode;

  mode = 0;
  if (argc < 2)
    return (fprintf(stderr, "Usage : %s [-s] [-p <pid>|<command>]\n", av[0])
            || 1);
  if (!strcmp(av[1], "-s"))
    mode = 1;
  if (!strcmp(av[1 + mode], "-p") && av[2 + mode])
    {
      if (attach_to_running_process((pid = (pid_t)atoi(av[2]))))
        return (EXIT_FAILURE);
    }
  else
    {
      pid = fork();
      if (pid == 0)
        return (launch_child(argc, av, mode));
    }
  return (print_exit(trace(pid, mode), mode));
}
