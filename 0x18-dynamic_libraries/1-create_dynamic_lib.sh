#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 -shared  -o liball.so -fPIC  *.c
