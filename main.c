/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Sat Apr 15 20:40:13 2017 theo champion
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
      return (1);
    }
  return (0);
}

static int	launch_child(int argc, char **argv, char * const *env)
{
  char		*exe;
  char		*args[argc+1];
  int		i;

  i = -1;
  while (++i < argc)
    args[i] = argv[i + 1];
  args[argc] = NULL;
  ptrace(PTRACE_TRACEME);
  exe = getpath(argv[1], env);
  kill(getpid(), SIGSTOP);
  execve(exe, args, env);
  free(exe);
  return (0);
}

int				trace(pid_t pid)
{
  struct user_regs_struct	r;
  struct user_regs_struct	r_ret;
  unsigned short		instr_code;
  int				wait_status;
  int				syscall;

  waitpid(pid, &wait_status, 0);
  while (signal_status_handler(wait_status))
    {
    syscall = 0;
    if (ptrace(PTRACE_GETREGS, pid, 0, &r))
      perror("ptrace");
    instr_code = ptrace(PTRACE_PEEKTEXT, pid, r.rip, 0);
    if (instr_code == SYSCALL_CODE)
      syscall = 1;
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
      perror("ptrace");
    waitpid(pid, &wait_status, 0);
    if (signal_status_handler(wait_status))
      {
        if (ptrace(PTRACE_GETREGS, pid, 0, &r_ret))
          perror("ptrace");
        if (syscall)
          print_syscall(pid, r.rax, r_ret.rax);
      }
    }
  return (wait_status);
}

int		main(int argc, char **argv, char * const *env)
{
    pid_t	pid;
    int		exit_status;

    if (argc < 2)
      {
        fprintf(stderr, "Usage : %s [-s] [-p <pid>|<command>]\n", argv[0]);
        exit(1);
      }
    if (!strcmp(argv[1], "-p"))
      attach_to_running_process((pid = (pid_t)atoi(argv[2])));
    else
      {
        pid = fork();
        if (pid == 0)
          return (launch_child(argc, argv, env));
      }
    exit_status = trace(pid);
    if (WIFEXITED(exit_status))
      fprintf(stderr, "exit_group(0x%x) = ?\n+++ exited with %d +++\n",
             WEXITSTATUS(exit_status), WEXITSTATUS(exit_status));
    return (0);
}
