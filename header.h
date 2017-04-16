/*
** header.h for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:14:25 2017 theo champion
** Last update Sun Apr 16 18:51:35 2017 theo champion
*/

#ifndef _HEADER_H_
#define _HEADER_H_

#include <sys/ptrace.h>
#include <ctype.h>
#include <sys/user.h>
#include <sys/reg.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

#define SYSCALL_CODE 0x050F
#define EXIT_SYSCALL 231
#define FUNC_MAX_LEN 50
#define MAX_SYSCALL_NUM 331
#define SYSCALL_MAXARGS 6
#define PATHFLAG "PATH="

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

enum e_arg_type {
    INT,
    PTR,
    STR
};

typedef struct		s_entry
{
  const char		*name;
  int			nb_args;
  enum e_arg_type	args_value[SYSCALL_MAXARGS];
}			t_entry;

// TRACE.C
void	print_syscall(pid_t child, unsigned long long sysnum,
		      unsigned long long retval, int mode);
// GETPATH.C
char	*getpath(char *bin, char * const *env);
//PRINT.C
void	print_arg(pid_t child, unsigned long long arg, int mode,
		  enum e_arg_type type);
int	print_exit(int exit_status, int mode);

#endif /* !_HEADER_H_ */
