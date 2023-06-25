# C Simple Shell
Implementing the concepts of [UNIX shell](https://en.wikipedia.org/wiki/Unix_shell), [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell), and other concepts already learnt in C programming language, we were tasked to build our own Command Line Interpreter with an interactive user interface and a non-interactive mode, the so-called `simple_shell`.

## Getting Started

- Ubuntu 20.04 LTS - Operating system required.

- GCC 9.4.0 - Compiler used.

## What’s Required
- Ubuntu Terminal or any other VM Sandbox.

## Usage
First, you need to compile the shell using this `gcc` command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
Then you can go ahead and run several shell commands to test the program out. A simple illustration has been shown below.

The shell works like this in an interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
In a non-interactive mode, you should see this:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

# Authors
- ***Felix Ayot*** < felixayot@gmail.com >
- ***Brian Kamau*** < bmaina031@gmail.com >

# Acknowledgments
- ALX SE program provided the resources and project guidance. More information on this amazing program can be found through this [link](https://www.alxafrica.com/).
