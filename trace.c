/*
** trace.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Thu Apr 13 17:20:15 2017 theo champion
** Last update Sat Apr 15 20:25:17 2017 theo champion
*/

#include "header.h"
#include "syscalls_entries.h"

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
    snprintf(buf, sizeof(buf), "sys_%d", scn);
    return (buf);
}

static long	get_syscall_arg(pid_t child, int arg_nb)
{
  int		regs[SYSCALL_MAXARGS];

  regs[0] = RDI;
  regs[1] = RSI;
  regs[2] = RDX;
  regs[3] = R10;
  regs[4] = R8;
  regs[5] = R9;
  return (get_register_value(child, regs[arg_nb]));
}

static void			print_syscall_args(pid_t child, int num)
{
    t_entry			*ent;
    int				nb_args;
    int				i;
    uint32_t			arg;

    ent = NULL;
    nb_args = SYSCALL_MAXARGS;
    if (num <= MAX_SYSCALL_NUM && g_entries[num].name)
      {
        ent = &g_entries[num];
        nb_args = ent->nb_args;
      }
    i = 0;
    while (i < nb_args)
      {
        arg = get_syscall_arg(child, i);
        arg ? fprintf(stderr, "0x%x", arg) : fprintf(stderr, "0x0");
        if (i++ != nb_args - 1)
          fprintf(stderr, ", ");
      }
}

void	print_syscall(pid_t child, uint32_t sysnum, uint32_t retval)
{
    fprintf(stderr, "%s(", get_syscall_name(sysnum));
    print_syscall_args(child, sysnum);
    fprintf(stderr, ") = ");
    retval ? fprintf(stderr, "0x%x\n", retval) : fprintf(stderr, "0x0\n");
}
