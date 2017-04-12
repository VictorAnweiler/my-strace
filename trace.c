/*
** trace.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:12:38 2017 theo champion
** Last update Wed Apr 12 17:13:13 2017 theo champion
*/

#include "header.h"

int	launch_child(char **argv, char **env)
{
  char	**args;

  args = (char **)argv[2];
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
  bool				syscall;

  waitpid(pid, &wait_status, 0);
  while (WIFSTOPPED(wait_status)
	 && (WSTOPSIG(wait_status) == SIGTRAP
	     || WSTOPSIG(wait_status) == SIGSTOP))
    {
    syscall = false;
    if (ptrace(PTRACE_GETREGS, pid, 0, &r))
      perror("ptrace getregs:");
    instr_code = ptrace(PTRACE_PEEKTEXT, pid, r.rip, 0);
    if (instr_code == SYSCALL_CODE)
      syscall = true;
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
      perror("ptrace singlestep");
    waitpid(pid, &wait_status, 0);
    if (ptrace(PTRACE_GETREGS, pid, 0, &r_ret))
      perror("ptrace getregs:");
    if (syscall)
      printf("reg rax %llu res ret %llu\n", r.rax, r_ret.rax);
  }
  return (wait_status);
}
