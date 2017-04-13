/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Thu Apr 13 21:02:04 2017 theo champion
*/

#include "header.h"

static int	attach_to_running_process(pid_t pid)
{
  if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
    perror("Ptrace attach: ");
    return (1);
  }
  return (0);
}

static int	launch_child(char **argv, char * const *env)
{
  char		**args;
  char		*exe;

  args = (char **)argv[2];
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
  while (WIFSTOPPED(wait_status)
         && (WSTOPSIG(wait_status) == SIGTRAP
             || WSTOPSIG(wait_status) == SIGSTOP))
    {
    syscall = 0;
    if (ptrace(PTRACE_GETREGS, pid, 0, &r))
      perror("ptrace1 getregs:");
    instr_code = ptrace(PTRACE_PEEKTEXT, pid, r.rip, 0);
    if (instr_code == SYSCALL_CODE)
      syscall = 1;
    if (ptrace(PTRACE_SINGLESTEP, pid, 0, 0) == -1)
      perror("ptrace singlestep");
    waitpid(pid, &wait_status, 0);
    if (WIFSTOPPED(wait_status)
         && (WSTOPSIG(wait_status) == SIGTRAP
             || WSTOPSIG(wait_status) == SIGSTOP)) {
      if (ptrace(PTRACE_GETREGS, pid, 0, &r_ret))
        perror("ptrace2 getregs:");
    }
    if (syscall == 1)
      {
	if (r.rax == 231)
	  printf("exit_group(0x0)      = ?\n+++ exited with 0 +++\n");
	else
	  print_syscall(pid, r.rax, r_ret.rax);
      }
    }
  return (wait_status);
}

int		main(int argc, char **argv, char * const *env)
{
    pid_t	pid;

    if (argc < 2) {
        fprintf(stderr, "Usage : %s [-s] [-p <pid>|<command>]\n", argv[0]);
        exit(1);
    }
    if (!strcmp(argv[1], "-p"))
      attach_to_running_process((pid = (pid_t)atoi(argv[2])));
    else
      {
        pid = fork();
        if (pid == 0)
          return (launch_child(argv, env));
      }
    return (trace(pid));
}
