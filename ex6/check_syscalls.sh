#!/bin/bash

####################
# Lab 1 Exercise 6
# Name: Wincent Tjoi
# Student No: A0201480W
# Lab Group: 06
####################

echo "Printing system call report"

# Compile file
gcc -std=c99 pid_checker.c -o ex6

# Use strace to get report
strace -c ./pid_checker