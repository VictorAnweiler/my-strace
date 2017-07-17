# my-strace

This is a second year Epitech project, it is therefore subjected to the "C Norm" wich is a programming style convention created by the school.  
The full epitech norm is available here: https://youtrack.jetbrains.com/_persistent/norme-en.pdf?file=74-190945&v=0&c=true
If some parts of the code seems weird in their syntax, it's probably due to this norm.

The purpose of this project was to implement the strace diagnostic and debugging utility for linux.

```sh
Usage : ./strace [-s] [-p <pid>|<command>]
    -s : show arguments details
    -p : PID of the process to attach
```

Forbidden functionnality:

* PTRACE_SYSCALL


## Grade : 18.7/20
