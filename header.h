/*
** header.h for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Wed Apr 12 11:14:25 2017 theo champion
** Last update Wed Apr 12 17:11:40 2017 theo champion
*/

#ifndef _HEADER_H_
#define _HEADER_H_

#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/user.h>
#include <stdbool.h>

#define SYSCALL_CODE 0x050F

int launch_child(char **argv, char **env);
int trace(pid_t child);

#endif /* !_HEADER_H_ */
