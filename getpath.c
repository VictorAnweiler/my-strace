/*
** getpath.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Thu Apr 13 18:35:10 2017 theo champion
** Last update Thu Apr 13 18:43:03 2017 theo champion
*/

#include "header.h"

static int	ispath(const char *str)
{
  char	*test;
  int	i;

  if (strlen(str) < strlen(PATHFLAG))
    return (0);
  test = strdup(PATHFLAG);
  i = -1;
  while (test[++i])
    if (test[i] != str[i])
      {
	free(test);
	return (0);
      }
  free(test);
  return (1);
}

static char	*getgoodpath(const char *bin, const char *env)
{
  int		i;
  int		j;
  char		*tmp;
  struct stat	sb;

  env += strlen(PATHFLAG);
  i = -1;
  while ((unsigned int)++i <= strlen(env))
    {
      j = 0;
      while (env[i+j] && env[i+j] != 0x3A)
	j++;
      if (!(tmp = malloc(sizeof(char) * j + 2 + strlen(bin))))
	return (NULL);
      tmp = strncpy(tmp, env + i, j);
      *(tmp + j) = 0x2F;
      memcpy(tmp + j + 1, bin, strlen(bin) + 1);
      if (stat(tmp, &sb) == 0 && sb.st_mode & S_IXUSR)
	return (tmp);
      free(tmp);
      i += j;
    }
  return (NULL);
}

char	*getpath(const char *bin, char * const *env)
{
  int	i;

  i = i ^ i;
  while (env[i])
    {
      if (ispath(env[i]))
	return (getgoodpath(bin, env[i]));
      i++;
    }
  return (NULL);
}
