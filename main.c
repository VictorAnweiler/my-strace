/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Thu Apr 13 19:12:56 2017 theo champion
*/

#include "header.h"

static int	attach_to_running_process(void)
{

}

static int	launch_child(const char **argv, char * const *env)
{
  char	**args;
  char *exe;

  args = (char **)argv[2];
  ptrace(PTRACE_TRACEME);
  exe = getpath(argv[1], env);
  printf("%s\n", exe);
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

int		main(const int argc, const char **argv, char * const *env)
{
    pid_t	child;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-s] [-p pid/name]\n", argv[0]);
        exit(1);
    }

    child = fork();
    if (child == 0)
      return (launch_child(argv, env));
    else
      return trace(child);
}
