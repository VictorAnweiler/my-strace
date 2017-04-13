/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Thu Apr 13 12:55:03 2017 theo champion
*/

#include "header.h"

int	main(int argc, char **argv, char **env) {

  if (argc < 2) {
    fprintf(stderr, "Usage : %s [-s] [-p <pid>|<command>]", argv[0]);
    exit(1);
  }

  return (execve("./strace", argv, env));
}
