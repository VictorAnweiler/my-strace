/*
** print.c for strace in /home/rootkid/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Sun Apr 16 18:14:01 2017 theo champion
** Last update Sun Apr 16 19:12:39 2017 theo champion
*/

#include "header.h"

static char		*read_string(pid_t child, unsigned long addr) {
  char			*val;
  unsigned long long	allocated;
  unsigned long long	read;
  unsigned long long	tmp;

  allocated = 4096;
  if ((val = malloc(allocated)) == NULL)
    return (NULL);
  read = 0;
  while (1)
    {
      if (read + sizeof(tmp) > allocated)
        val = realloc(val, allocated *= 2);
      tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
      if (errno != 0)
        {
          val[read] = 0;
          break;
        }
      memcpy(val + read, &tmp, sizeof(tmp));
      if (memchr(&tmp, 0, sizeof(tmp)) != NULL)
        break;
      read += sizeof(tmp);
    }
  return (val);
}

void	print_arg(pid_t child, unsigned long long arg, int mode,
		  enum e_arg_type type)
{
  char	*str;
  int	h;

  if (mode && type == INT)
    fprintf(stderr, "%lld", arg);
  else if (mode && type == STR)
    {
      str = read_string(child, arg);
      h = -1;
      fprintf(stderr, "\"");
      while (str[++h] && h < 32)
        fprintf(stderr, isprint(str[h]) ? "%c" : "\\%o", str[h]);
      h >= 32 ?fprintf(stderr, "\"...") : fprintf(stderr, "\"");
      free(str);
    }
  else
    arg ? fprintf(stderr, "0x%llx", arg)
      : fprintf(stderr, (mode ? "NULL" : "0x0"));
}

int	print_exit(int exit_status, int mode)
{
  if (WIFEXITED(exit_status))
    {
      fprintf(stderr, mode ? "exit_group(%d) = ?\n"
              : "exit_group(0x%x) = ?\n", WEXITSTATUS(exit_status));
      fprintf(stderr, "+++ exited with %d +++\n", WEXITSTATUS(exit_status));
    }
  return (EXIT_SUCCESS);
}
