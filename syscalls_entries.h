/*
** syscalls_entries.c for strace in /home/rootkid/rendu/psu/PSU_2016_strace
** 
** Made by theo champion
** Login   <theo.champion@epitech.eu>
** 
** Started on  Fri Apr 14 14:12:54 2017 theo champion
** Last update Sun Apr 16 17:00:09 2017 theo champion
*/

#ifndef _SYSCALLS_ENTRIES_H_
#define _SYSCALLS_ENTRIES_H_

static t_entry		g_entries[] = {
  [0] = {
    .name  = "read",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [1] = {
    .name  = "write",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [2] = {
    .name  = "open",
    .args_value  = {STR, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [3] = {
    .name  = "close",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [4] = {
    .name  = "stat",
    .args_value  = {STR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [5] = {
    .name  = "fstat",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [6] = {
    .name  = "lstat",
    .args_value  = {STR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [7] = {
    .name  = "poll",
    .args_value  = {PTR, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [8] = {
    .name  = "lseek",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [9] = {
    .name  = "mmap",
    .args_value  = {INT, INT, INT, INT, INT, INT},
    .nb_args = 6,
  },
  [10] = {
    .name  = "mprotect",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [11] = {
    .name  = "munmap",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [12] = {
    .name  = "brk",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [13] = {
    .name  = "rt_sigaction",
    .args_value  = {INT, PTR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [14] = {
    .name  = "rt_sigprocmask",
    .args_value  = {INT, PTR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [15] = {
    .name  = "rt_sigreturn",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [16] = {
    .name  = "ioctl",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [17] = {
    .name  = "pread64",
    .args_value  = {INT, STR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [18] = {
    .name  = "pwrite64",
    .args_value  = {INT, STR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [19] = {
    .name  = "readv",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [20] = {
    .name  = "writev",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [21] = {
    .name  = "access",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [22] = {
    .name  = "pipe",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [23] = {
    .name  = "select",
    .args_value  = {INT, PTR, PTR, PTR, PTR, -1},
    .nb_args = 5,
  },
  [24] = {
    .name  = "sched_yield",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [25] = {
    .name  = "mremap",
    .args_value  = {INT, INT, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [26] = {
    .name  = "msync",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [27] = {
    .name  = "mincore",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [28] = {
    .name  = "madvise",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [29] = {
    .name  = "shmget",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [30] = {
    .name  = "shmat",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [31] = {
    .name  = "shmctl",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [32] = {
    .name  = "dup",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [33] = {
    .name  = "dup2",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [34] = {
    .name  = "pause",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [35] = {
    .name  = "nanosleep",
    .args_value  = {PTR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [36] = {
    .name  = "getitimer",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [37] = {
    .name  = "alarm",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [38] = {
    .name  = "setitimer",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [39] = {
    .name  = "getpid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [40] = {
    .name  = "sendfile",
    .args_value  = {INT, INT, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [41] = {
    .name  = "socket",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [42] = {
    .name  = "connect",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [43] = {
    .name  = "accept",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [44] = {
    .name  = "sendto",
    .args_value  = {INT, PTR, INT, INT, PTR, INT},
    .nb_args = 6,
  },
  [45] = {
    .name  = "recvfrom",
    .args_value  = {INT, PTR, INT, INT, PTR, PTR},
    .nb_args = 6,
  },
  [46] = {
    .name  = "sendmsg",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [47] = {
    .name  = "recvmsg",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [48] = {
    .name  = "shutdown",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [49] = {
    .name  = "bind",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [50] = {
    .name  = "listen",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [51] = {
    .name  = "getsockname",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [52] = {
    .name  = "getpeername",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [53] = {
    .name  = "socketpair",
    .args_value  = {INT, INT, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [54] = {
    .name  = "setsockopt",
    .args_value  = {INT, INT, INT, STR, INT, -1},
    .nb_args = 5,
  },
  [55] = {
    .name  = "getsockopt",
    .args_value  = {INT, INT, INT, STR, PTR, -1},
    .nb_args = 5,
  },
  [56] = {
    .name  = "clone",
    .args_value  = {INT, INT, PTR, PTR, INT, -1},
    .nb_args = 5,
  },
  [57] = {
    .name  = "fork",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [58] = {
    .name  = "vfork",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [59] = {
    .name  = "execve",
    .args_value  = {STR, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [60] = {
    .name  = "exit",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [61] = {
    .name  = "wait4",
    .args_value  = {INT, PTR, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [62] = {
    .name  = "kill",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [63] = {
    .name  = "uname",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [64] = {
    .name  = "semget",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [65] = {
    .name  = "semop",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [66] = {
    .name  = "semctl",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [67] = {
    .name  = "shmdt",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [68] = {
    .name  = "msgget",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [69] = {
    .name  = "msgsnd",
    .args_value  = {INT, PTR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [70] = {
    .name  = "msgrcv",
    .args_value  = {INT, PTR, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [71] = {
    .name  = "msgctl",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [72] = {
    .name  = "fcntl",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [73] = {
    .name  = "flock",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [74] = {
    .name  = "fsync",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [75] = {
    .name  = "fdatasync",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [76] = {
    .name  = "truncate",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [77] = {
    .name  = "ftruncate",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [78] = {
    .name  = "getdents",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [79] = {
    .name  = "getcwd",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [80] = {
    .name  = "chdir",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [81] = {
    .name  = "fchdir",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [82] = {
    .name  = "rename",
    .args_value  = {STR, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [83] = {
    .name  = "mkdir",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [84] = {
    .name  = "rmdir",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [85] = {
    .name  = "creat",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [86] = {
    .name  = "link",
    .args_value  = {STR, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [87] = {
    .name  = "unlink",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [88] = {
    .name  = "symlink",
    .args_value  = {STR, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [89] = {
    .name  = "readlink",
    .args_value  = {STR, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [90] = {
    .name  = "chmod",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [91] = {
    .name  = "fchmod",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [92] = {
    .name  = "chown",
    .args_value  = {STR, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [93] = {
    .name  = "fchown",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [94] = {
    .name  = "lchown",
    .args_value  = {STR, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [95] = {
    .name  = "umask",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [96] = {
    .name  = "gettimeofday",
    .args_value  = {PTR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [97] = {
    .name  = "getrlimit",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [98] = {
    .name  = "getrusage",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [99] = {
    .name  = "sysinfo",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [100] = {
    .name  = "times",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [101] = {
    .name  = "ptrace",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [102] = {
    .name  = "getuid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [103] = {
    .name  = "syslog",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [104] = {
    .name  = "getgid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [105] = {
    .name  = "setuid",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [106] = {
    .name  = "setgid",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [107] = {
    .name  = "geteuid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [108] = {
    .name  = "getegid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [109] = {
    .name  = "setpgid",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [110] = {
    .name  = "getppid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [111] = {
    .name  = "getpgrp",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [112] = {
    .name  = "setsid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [113] = {
    .name  = "setreuid",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [114] = {
    .name  = "setregid",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [115] = {
    .name  = "getgroups",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [116] = {
    .name  = "setgroups",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [117] = {
    .name  = "setresuid",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [118] = {
    .name  = "getresuid",
    .args_value  = {PTR, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [119] = {
    .name  = "setresgid",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [120] = {
    .name  = "getresgid",
    .args_value  = {PTR, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [121] = {
    .name  = "getpgid",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [122] = {
    .name  = "setfsuid",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [123] = {
    .name  = "setfsgid",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [124] = {
    .name  = "getsid",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [125] = {
    .name  = "capget",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [126] = {
    .name  = "capset",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [127] = {
    .name  = "rt_sigpending",
    .args_value  = {PTR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [128] = {
    .name  = "rt_sigtimedwait",
    .args_value  = {PTR, PTR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [129] = {
    .name  = "rt_sigqueueinfo",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [130] = {
    .name  = "rt_sigsuspend",
    .args_value  = {PTR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [131] = {
    .name  = "sigaltstack",
    .args_value  = {PTR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [132] = {
    .name  = "utime",
    .args_value  = {STR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [133] = {
    .name  = "mknod",
    .args_value  = {STR, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [134] = {
    .name  = "uselib",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [135] = {
    .name  = "personality",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [136] = {
    .name  = "ustat",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [137] = {
    .name  = "statfs",
    .args_value  = {STR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [138] = {
    .name  = "fstatfs",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [139] = {
    .name  = "sysfs",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [140] = {
    .name  = "getpriority",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [141] = {
    .name  = "setpriority",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [142] = {
    .name  = "sched_setparam",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [143] = {
    .name  = "sched_getparam",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [144] = {
    .name  = "sched_setscheduler",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [145] = {
    .name  = "sched_getscheduler",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [146] = {
    .name  = "sched_get_priority_max",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [147] = {
    .name  = "sched_get_priority_min",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [148] = {
    .name  = "sched_rr_get_interval",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [149] = {
    .name  = "mlock",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [150] = {
    .name  = "munlock",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [151] = {
    .name  = "mlockall",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [152] = {
    .name  = "munlockall",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [153] = {
    .name  = "vhangup",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [154] = {
    .name  = "modify_ldt",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [155] = {
    .name  = "pivot_root",
    .args_value  = {STR, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [156] = {
    .name  = "_sysctl",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [157] = {
    .name  = "prctl",
    .args_value  = {INT, INT, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [158] = {
    .name  = "arch_prctl",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [159] = {
    .name  = "adjtimex",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [160] = {
    .name  = "setrlimit",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [161] = {
    .name  = "chroot",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [162] = {
    .name  = "sync",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [163] = {
    .name  = "acct",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [164] = {
    .name  = "settimeofday",
    .args_value  = {PTR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [165] = {
    .name  = "mount",
    .args_value  = {STR, STR, STR, INT, PTR, -1},
    .nb_args = 5,
  },
  [166] = {
    .name  = "umount2",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [167] = {
    .name  = "swapon",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [168] = {
    .name  = "swapoff",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [169] = {
    .name  = "reboot",
    .args_value  = {INT, INT, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [170] = {
    .name  = "sethostname",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [171] = {
    .name  = "setdomainname",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [172] = {
    .name  = "iopl",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [173] = {
    .name  = "ioperm",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [174] = {
    .name  = "create_module",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [175] = {
    .name  = "init_module",
    .args_value  = {PTR, INT, STR, -1, -1, -1},
    .nb_args = 3,
  },
  [176] = {
    .name  = "delete_module",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [177] = {
    .name  = "get_kernel_syms",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [178] = {
    .name  = "query_module",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [179] = {
    .name  = "quotactl",
    .args_value  = {INT, STR, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [180] = {
    .name  = "nfsservctl",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [181] = {
    .name  = "getpmsg",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [182] = {
    .name  = "putpmsg",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [183] = {
    .name  = "afs_syscall",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [184] = {
    .name  = "tuxcall",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [185] = {
    .name  = "security",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [186] = {
    .name  = "gettid",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [187] = {
    .name  = "readahead",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [188] = {
    .name  = "setxattr",
    .args_value  = {STR, STR, PTR, INT, INT, -1},
    .nb_args = 5,
  },
  [189] = {
    .name  = "lsetxattr",
    .args_value  = {STR, STR, PTR, INT, INT, -1},
    .nb_args = 5,
  },
  [190] = {
    .name  = "fsetxattr",
    .args_value  = {INT, STR, PTR, INT, INT, -1},
    .nb_args = 5,
  },
  [191] = {
    .name  = "getxattr",
    .args_value  = {STR, STR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [192] = {
    .name  = "lgetxattr",
    .args_value  = {STR, STR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [193] = {
    .name  = "fgetxattr",
    .args_value  = {INT, STR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [194] = {
    .name  = "listxattr",
    .args_value  = {STR, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [195] = {
    .name  = "llistxattr",
    .args_value  = {STR, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [196] = {
    .name  = "flistxattr",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [197] = {
    .name  = "removexattr",
    .args_value  = {STR, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [198] = {
    .name  = "lremovexattr",
    .args_value  = {STR, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [199] = {
    .name  = "fremovexattr",
    .args_value  = {INT, STR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [200] = {
    .name  = "tkill",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [201] = {
    .name  = "time",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [202] = {
    .name  = "futex",
    .args_value  = {PTR, INT, INT, PTR, PTR, INT},
    .nb_args = 6,
  },
  [203] = {
    .name  = "sched_setaffinity",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [204] = {
    .name  = "sched_getaffinity",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [205] = {
    .name  = "set_thread_area",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [206] = {
    .name  = "io_setup",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [207] = {
    .name  = "io_destroy",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [208] = {
    .name  = "io_getevents",
    .args_value  = {INT, INT, INT, PTR, PTR, -1},
    .nb_args = 5,
  },
  [209] = {
    .name  = "io_submit",
    .args_value  = {INT, INT, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [210] = {
    .name  = "io_cancel",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [211] = {
    .name  = "get_thread_area",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [212] = {
    .name  = "lookup_dcookie",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [213] = {
    .name  = "epoll_create",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [214] = {
    .name  = "epoll_ctl_old",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [215] = {
    .name  = "epoll_wait_old",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [216] = {
    .name  = "remap_file_pages",
    .args_value  = {INT, INT, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [217] = {
    .name  = "getdents64",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [218] = {
    .name  = "set_tid_address",
    .args_value  = {PTR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [219] = {
    .name  = "restart_syscall",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [220] = {
    .name  = "semtimedop",
    .args_value  = {INT, PTR, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [221] = {
    .name  = "fadvise64",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [222] = {
    .name  = "timer_create",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [223] = {
    .name  = "timer_settime",
    .args_value  = {INT, INT, PTR, PTR, -1, -1},
    .nb_args = 4,
  },
  [224] = {
    .name  = "timer_gettime",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [225] = {
    .name  = "timer_getoverrun",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [226] = {
    .name  = "timer_delete",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [227] = {
    .name  = "clock_settime",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [228] = {
    .name  = "clock_gettime",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [229] = {
    .name  = "clock_getres",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [230] = {
    .name  = "clock_nanosleep",
    .args_value  = {INT, INT, PTR, PTR, -1, -1},
    .nb_args = 4,
  },
  [231] = {
    .name  = "exit_group",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [232] = {
    .name  = "epoll_wait",
    .args_value  = {INT, PTR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [233] = {
    .name  = "epoll_ctl",
    .args_value  = {INT, INT, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [234] = {
    .name  = "tgkill",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [235] = {
    .name  = "utimes",
    .args_value  = {STR, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [236] = {
    .name  = "vserver",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [237] = {
    .name  = "mbind",
    .args_value  = {INT, INT, INT, PTR, INT, INT},
    .nb_args = 6,
  },
  [238] = {
    .name  = "set_mempolicy",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [239] = {
    .name  = "get_mempolicy",
    .args_value  = {PTR, PTR, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [240] = {
    .name  = "mq_open",
    .args_value  = {STR, INT, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [241] = {
    .name  = "mq_unlink",
    .args_value  = {STR, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [242] = {
    .name  = "mq_timedsend",
    .args_value  = {INT, STR, INT, INT, PTR, -1},
    .nb_args = 5,
  },
  [243] = {
    .name  = "mq_timedreceive",
    .args_value  = {INT, STR, INT, PTR, PTR, -1},
    .nb_args = 5,
  },
  [244] = {
    .name  = "mq_notify",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [245] = {
    .name  = "mq_getsetattr",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [246] = {
    .name  = "kexec_load",
    .args_value  = {INT, INT, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [247] = {
    .name  = "waitid",
    .args_value  = {INT, INT, PTR, INT, PTR, -1},
    .nb_args = 5,
  },
  [248] = {
    .name  = "add_key",
    .args_value  = {STR, STR, PTR, INT, INT, -1},
    .nb_args = 5,
  },
  [249] = {
    .name  = "request_key",
    .args_value  = {STR, STR, STR, INT, -1, -1},
    .nb_args = 4,
  },
  [250] = {
    .name  = "keyctl",
    .args_value  = {INT, INT, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [251] = {
    .name  = "ioprio_set",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [252] = {
    .name  = "ioprio_get",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [253] = {
    .name  = "inotify_init",
    .args_value  = {-1, -1, -1, -1, -1, -1},
    .nb_args = 0,
  },
  [254] = {
    .name  = "inotify_add_watch",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [255] = {
    .name  = "inotify_rm_watch",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [256] = {
    .name  = "migrate_pages",
    .args_value  = {INT, INT, PTR, PTR, -1, -1},
    .nb_args = 4,
  },
  [257] = {
    .name  = "openat",
    .args_value  = {INT, STR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [258] = {
    .name  = "mkdirat",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [259] = {
    .name  = "mknodat",
    .args_value  = {INT, STR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [260] = {
    .name  = "fchownat",
    .args_value  = {INT, STR, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [261] = {
    .name  = "futimesat",
    .args_value  = {INT, STR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [262] = {
    .name  = "newfstatat",
    .args_value  = {INT, STR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [263] = {
    .name  = "unlinkat",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [264] = {
    .name  = "renameat",
    .args_value  = {INT, STR, INT, STR, -1, -1},
    .nb_args = 4,
  },
  [265] = {
    .name  = "linkat",
    .args_value  = {INT, STR, INT, STR, INT, -1},
    .nb_args = 5,
  },
  [266] = {
    .name  = "symlinkat",
    .args_value  = {STR, INT, STR, -1, -1, -1},
    .nb_args = 3,
  },
  [267] = {
    .name  = "readlinkat",
    .args_value  = {INT, STR, STR, INT, -1, -1},
    .nb_args = 4,
  },
  [268] = {
    .name  = "fchmodat",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [269] = {
    .name  = "faccessat",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [270] = {
    .name  = "pselect6",
    .args_value  = {INT, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [271] = {
    .name  = "ppoll",
    .args_value  = {PTR, INT, PTR, PTR, INT, -1},
    .nb_args = 5,
  },
  [272] = {
    .name  = "unshare",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [273] = {
    .name  = "set_robust_list",
    .args_value  = {PTR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [274] = {
    .name  = "get_robust_list",
    .args_value  = {INT, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [275] = {
    .name  = "splice",
    .args_value  = {INT, PTR, INT, PTR, INT, INT},
    .nb_args = 6,
  },
  [276] = {
    .name  = "tee",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [277] = {
    .name  = "sync_file_range",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [278] = {
    .name  = "vmsplice",
    .args_value  = {INT, PTR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [279] = {
    .name  = "move_pages",
    .args_value  = {INT, INT, PTR, PTR, PTR, INT},
    .nb_args = 6,
  },
  [280] = {
    .name  = "utimensat",
    .args_value  = {INT, STR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [281] = {
    .name  = "epoll_pwait",
    .args_value  = {INT, PTR, INT, INT, PTR, INT},
    .nb_args = 6,
  },
  [282] = {
    .name  = "signalfd",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [283] = {
    .name  = "timerfd_create",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [284] = {
    .name  = "eventfd",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [285] = {
    .name  = "fallocate",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [286] = {
    .name  = "timerfd_settime",
    .args_value  = {INT, INT, PTR, PTR, -1, -1},
    .nb_args = 4,
  },
  [287] = {
    .name  = "timerfd_gettime",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [288] = {
    .name  = "accept4",
    .args_value  = {INT, PTR, PTR, INT, -1, -1},
    .nb_args = 4,
  },
  [289] = {
    .name  = "signalfd4",
    .args_value  = {INT, PTR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [290] = {
    .name  = "eventfd2",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [291] = {
    .name  = "epoll_create1",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [292] = {
    .name  = "dup3",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [293] = {
    .name  = "pipe2",
    .args_value  = {PTR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [294] = {
    .name  = "inotify_init1",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [295] = {
    .name  = "preadv",
    .args_value  = {INT, PTR, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [296] = {
    .name  = "pwritev",
    .args_value  = {INT, PTR, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [297] = {
    .name  = "rt_tgsigqueueinfo",
    .args_value  = {INT, INT, INT, PTR, -1, -1},
    .nb_args = 4,
  },
  [298] = {
    .name  = "perf_event_open",
    .args_value  = {PTR, INT, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [299] = {
    .name  = "recvmmsg",
    .args_value  = {INT, PTR, INT, INT, PTR, -1},
    .nb_args = 5,
  },
  [300] = {
    .name  = "fanotify_init",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [301] = {
    .name  = "fanotify_mark",
    .args_value  = {INT, INT, INT, INT, STR, -1},
    .nb_args = 5,
  },
  [302] = {
    .name  = "prlimit64",
    .args_value  = {INT, INT, PTR, PTR, -1, -1},
    .nb_args = 4,
  },
  [303] = {
    .name  = "name_to_handle_at",
    .args_value  = {INT, STR, PTR, PTR, INT, -1},
    .nb_args = 5,
  },
  [304] = {
    .name  = "open_by_handle_at",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [305] = {
    .name  = "clock_adjtime",
    .args_value  = {INT, PTR, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [306] = {
    .name  = "syncfs",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [307] = {
    .name  = "sendmmsg",
    .args_value  = {INT, PTR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [308] = {
    .name  = "setns",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [309] = {
    .name  = "getcpu",
    .args_value  = {PTR, PTR, PTR, -1, -1, -1},
    .nb_args = 3,
  },
  [310] = {
    .name  = "process_vm_readv",
    .args_value  = {INT, PTR, INT, PTR, INT, INT},
    .nb_args = 6,
  },
  [311] = {
    .name  = "process_vm_writev",
    .args_value  = {INT, PTR, INT, PTR, INT, INT},
    .nb_args = 6,
  },
  [312] = {
    .name  = "kcmp",
    .args_value  = {INT, INT, INT, INT, INT, -1},
    .nb_args = 5,
  },
  [313] = {
    .name  = "finit_module",
    .args_value  = {INT, STR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [314] = {
    .name  = "sched_setattr",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [315] = {
    .name  = "sched_getattr",
    .args_value  = {INT, PTR, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [316] = {
    .name  = "renameat2",
    .args_value  = {INT, STR, INT, STR, INT, -1},
    .nb_args = 5,
  },
  [317] = {
    .name  = "seccomp",
    .args_value  = {INT, INT, STR, -1, -1, -1},
    .nb_args = 3,
  },
  [318] = {
    .name  = "getrandom",
    .args_value  = {PTR, PTR, PTR, PTR, PTR, PTR},
    .nb_args = 6,
  },
  [319] = {
    .name  = "memfd_create",
    .args_value  = {STR, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [320] = {
    .name  = "kexec_file_load",
    .args_value  = {INT, INT, INT, STR, INT, -1},
    .nb_args = 5,
  },
  [321] = {
    .name  = "bpf",
    .args_value  = {INT, PTR, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [322] = {
    .name  = "execveat",
    .args_value  = {INT, STR, PTR, PTR, INT, -1},
    .nb_args = 5,
  },
  [323] = {
    .name  = "userfaultfd",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  },
  [324] = {
    .name  = "membarrier",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [325] = {
    .name  = "mlock2",
    .args_value  = {INT, INT, INT, -1, -1, -1},
    .nb_args = 3,
  },
  [326] = {
    .name  = "copy_file_range",
    .args_value  = {INT, PTR, INT, PTR, INT, INT},
    .nb_args = 6,
  },
  [327] = {
    .name  = "preadv2",
    .args_value  = {INT, PTR, INT, INT, INT, INT},
    .nb_args = 6,
  },
  [328] = {
    .name  = "pwritev2",
    .args_value  = {INT, PTR, INT, INT, INT, INT},
    .nb_args = 6,
  },
  [329] = {
    .name  = "pkey_mprotect",
    .args_value  = {INT, INT, INT, INT, -1, -1},
    .nb_args = 4,
  },
  [330] = {
    .name  = "pkey_alloc",
    .args_value  = {INT, INT, -1, -1, -1, -1},
    .nb_args = 2,
  },
  [331] = {
    .name  = "pkey_free",
    .args_value  = {INT, -1, -1, -1, -1, -1},
    .nb_args = 1,
  }
};

#endif /* !_SYSCALLS_ENTRIES_H_ */
