/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Thu Apr 13 18:18:37 2017 theo champion
*/

#include "header.h"

int	launch_child(char **argv, char **env)
{
  char	**args;

  args = (char **)argv[2];
  printf("args = %s\n", argv[3]);
  ptrace(PTRACE_TRACEME);
  kill(getpid(), SIGSTOP);
  return (execve(argv[1], args, env));
}

int				trace(pid_t pid)
{
  struct user_regs_struct	r;
  struct user_regs_struct	r_ret;
  unsigned short		instr_code;
  int				wait_status;
  int				syscall;

  waitpid(pid, &wait_status, 0);
  while (WIFSTOPPED(wait_status)
	 && (WSTOPSIG(wait_status) == SIGTRAP
	     || WSTOPSIG(wait_status) == SIGSTOP))
    {
    syscall = 0;
    if (ptrace(PTRACE_GETREGS, pid, 0, &r))
      perror("ptrace getregs:");
    instr_code = ptrace(PTRACE_PEEKTEXT, pid, r.rip, 0);
    if (instr_code == SYSCALL_CODE)
      syscall = 1;
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
      perror("ptrace singlestep");
    waitpid(pid, &wait_status, 0);
    if (ptrace(PTRACE_GETREGS, pid, 0, &r_ret))
      perror("ptrace getregs:");
    if (syscall == 1)
      print_syscall(pid, r.rax, r_ret.rax);
  }
  return (wait_status);
}

int		main(int argc, char **argv, char **env)
{
    pid_t	child;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-s] [-p pid/name]\n", argv[0]);
        exit(1);
    }

    child = fork();
    if (child == 0) {
      return launch_child(argv, env);
    } else {
        return trace(child);
    }
}
