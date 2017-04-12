/*
** main.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:13:34 2017 theo champion
** Last update Wed Apr 12 16:41:35 2017 theo champion
*/

#include "header.h"

int main(int argc, char **argv, char **env) {
  pid_t	p_child;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s prog args\n", argv[0]);
    exit(1);
  }

  p_child = fork();
  if (p_child == 0)
    return launch_child(argv, env);
  else
    return trace(p_child);
}
