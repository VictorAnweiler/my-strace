/*
** trace.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Thu Apr 13 17:20:15 2017 theo champion
** Last update Thu Apr 13 20:37:54 2017 theo champion
*/

#include "header.h"

static uint32_t	get_register_value(pid_t child, int pos)
{
  int		offset;
  uint32_t	value;

  offset = sizeof(unsigned long long) * pos;
  value = ptrace(PTRACE_PEEKUSER, child, offset);
  return (value);
}

const char			*get_syscall_name(int scn)
{
    t_entry			*ent;
    static char			buf[FUNC_MAX_LEN];

    if (scn <= MAX_SYSCALL_NUM)
      {
        ent = &g_entries[scn];
        if (ent->name)
          return (ent->name);
      }
    snprintf(buf, sizeof buf, "sys_%d", scn);
    return (buf);
}

static long	get_syscall_arg(pid_t child, int arg_nb)
{
  switch (arg_nb)
    {
    case 0:
      return (get_register_value(child, RDI));
    case 1:
      return (get_register_value(child, RSI));
    case 2:
      return (get_register_value(child, RDX));
    case 3:
      return (get_register_value(child, R10));
    case 4:
      return (get_register_value(child, R8));
    case 5:
      return (get_register_value(child, R9));
    default:
      return (-1L);
    }
}

static void			print_syscall_args(pid_t child, int num)
{
    t_entry			*ent = NULL;
    int				nargs;
    int				i;
    uint32_t			arg;

    nargs = SYSCALL_MAXARGS;
    if (num <= MAX_SYSCALL_NUM && g_entries[num].name)
      {
        ent = &g_entries[num];
        nargs = ent->nargs;
      }
    i = 0;
    while (i < nargs)
      {
        arg = get_syscall_arg(child, i);
        arg ? fprintf(stderr, "0x%x", arg) : fprintf(stderr, "0x0");
        if (i != nargs - 1)
          fprintf(stderr, ", ");
        i++;
    }
}

void	print_syscall(pid_t child, uint32_t sysnum, uint32_t retval)
{
    fprintf(stderr, "%s(", get_syscall_name(sysnum));
    print_syscall_args(child, sysnum);
    fprintf(stderr, ") = ");
    retval ? fprintf(stderr, "0x%x\n", retval) : fprintf(stderr, "0x0\n");
}
