/*
** getpath.c for PSU_2016_strace in /home/bufferking/rendu/psu_2016/PSU_2016_strace
** 
** Made by bufferking
** Login   <antoine.cauquil@epitech.eu>
** 
** Started on  Thu Apr 13 19:06:31 2017 
** Last update Thu Apr 13 19:27:26 2017 theo champion
*/

#include "header.h"

static int	ispath(const char *str)
{
  char		*test;
  int		i;

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

char	*getpath(char *bin, char * const *env)
{
  int		i;
  struct stat	sb;

  i = i ^ i;
  if (stat(bin, &sb) == 0 && sb.st_mode & S_IXUSR)
    return (bin);
  while (env[i])
    {
      if (ispath(env[i]))
	return (getgoodpath(bin, env[i]));
      i++;
    }
  return (NULL);
}
