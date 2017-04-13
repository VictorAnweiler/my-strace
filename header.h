/*
** header.h for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:14:25 2017 theo champion
** Last update Thu Apr 13 22:55:18 2017 theo champion
*/

#ifndef _HEADER_H_
#define _HEADER_H_

#include <sys/ptrace.h>
#include <bits/types.h>
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

enum argtype {
    ARG_INT,
    ARG_PTR,
    ARG_STR
};

typedef struct		s_entry
{
  const char *name;
  int nargs;
  enum argtype args[SYSCALL_MAXARGS];
}			t_entry;

extern t_entry g_entries[MAX_SYSCALL_NUM + 1];

// TRACE.C
void	print_syscall(pid_t child, uint32_t sysnum, uint32_t retval);
// GETPATH.C
char	*getpath(char *bin, char * const *env);

#endif /* !_HEADER_H_ */
