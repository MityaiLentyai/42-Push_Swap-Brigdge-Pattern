*This project has been created as part of the 42 curriculum by dzzayats, nsuszano*

## Description

This project implements a stack-sorting solution for the 42 Push Swap project. The goal is to sort the numbers in stack A in ascending order using only a restricted set of operations on two stacks, A and B. The program is designed to be correct, efficient, and easy to reason about, while also being scalable as the input size grows.

## Instructions

Usage:

```bash
make
./push_swap 3 2 1
./push_swap 2 1 3 6 5 8
```

Build the program with make. The executable is named push_swap. It accepts a list of integers as arguments, builds the initial stack, and prints the operations needed to sort the values. A valid solution sorts the stack in ascending order while respecting the allowed moves of the project.

To test quickly, you can run the program with small input examples and compare the output with the expected sorted order.

## Resources 

https://www.algorytm.edu.pl/algorytmy-maturalne/quick-sort.html
https://github.com/o-reo/push_swap_visualizer
https://medium.com/@ridwaneelfilali/push-swap-eff35d3ee0c4

## Algorithms and their justification

Simple:

Medium:

The medium strategy is designed for larger stacks that still benefit from a structured but understandable approach. It works by partitioning the values into chunks, pushing selected values to stack B, and then moving them back to stack A in a way that reduces unnecessary rotations. This is justified because it gives a strong balance between performance and simplicity: it avoids the worst-case cost of naive sorting while remaining implementable and readable within the project constraints.

Complex: 
