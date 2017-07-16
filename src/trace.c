/*
** trace.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Thu Apr 13 17:20:15 2017 theo champion
** Last update Sun Jul 16 02:20:39 2017 theo champion
*/

#include "strace.h"
#include "syscalls_entries.h"

static unsigned long long	get_register_value(pid_t child, int pos)
{
  int				offset;
  unsigned long long		value;

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

static unsigned long long	get_syscall_arg(pid_t child, int arg_nb)
{
  int				regs[SYSCALL_MAXARGS];

  regs[0] = RDI;
  regs[1] = RSI;
  regs[2] = RDX;
  regs[3] = R10;
  regs[4] = R8;
  regs[5] = R9;
  return (get_register_value(child, regs[arg_nb]));
}

static void			print_syscall_args(pid_t child,
						   int num, int mode)
{
  t_entry			*ent;
  int				nb_args;
  int				i;
  enum e_arg_type		type;
  unsigned long long		arg;

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
      type = ent ? ent->args_value[i] : PTR;
      print_arg(child, arg, mode, type);
      if (i++ != nb_args - 1)
        fprintf(stderr, ", ");
    }
}

void		print_syscall(pid_t child, unsigned long long sysnum,
                      unsigned long long retval, int mode)
{
  t_entry	*ent;

  fprintf(stderr, "%s(", get_syscall_name(sysnum));
  print_syscall_args(child, sysnum, mode);
  fprintf(stderr, ") = ");
  ent = &g_entries[sysnum];
  if (mode)
    fprintf(stderr, ent->retval == INT ? "%lld\n" : "0x%llx\n", retval);
  else
    retval ? fprintf(stderr, "0x%llx\n", retval)
      : fprintf(stderr, "0x0\n");
}
