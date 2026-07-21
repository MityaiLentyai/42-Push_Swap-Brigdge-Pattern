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

The simple strategy uses a selection-sort style approach. While the size of stack A is larger than 5, it repeatedly finds the smallest value, rotates the stack so that this minimum reaches the top, and pushes it to stack B. If the minimum is closer to the bottom half of the stack, the algorithm uses reverse rotations to minimize the number of moves. Once the stack is small enough, it switches to the dedicated small-stack solver and then moves all values from stack B back to stack A.

This approach is justified because it is straightforward and predictable: it keeps the logic easy to follow while still producing a valid solution for the constraints of the project. It is especially useful for smaller or moderately sized inputs where clarity matters more than maximal optimization.

Medium:

The medium strategy is designed for larger stacks that still benefit from a structured but understandable approach. It works by partitioning the values into chunks, pushing selected values to stack B, and then moving them back to stack A in a way that reduces unnecessary rotations. This is justified because it gives a strong balance between performance and simplicity: it avoids the worst-case cost of naive sorting while remaining implementable and readable within the project constraints.

Complex: 
The complex strategy uses a divide-and-conquer approach inspired by quicksort. It first checks whether the stack is small enough to delegate to the small-stack solver, and otherwise reassigns values to a normalized order so that the algorithm can reason about relative positions. The implementation then recursively splits the stack into smaller ranges: values below a median are pushed to stack B, while larger values stay in stack A, and the process repeats on both stacks until each part is small enough to finish with specialized handling.

This approach is justified because it reduces the number of costly moves by making many decisions locally and by keeping the work balanced between the two stacks. It is more efficient than the simpler strategies on larger inputs, while still remaining structured and understandable.

## Work divisioning 

Natalia was responsible for choosing, designing and implementing algorithms, parser 
and bonus part. Dzmitry helped with setting up the branches in github for remote work as well as 
some helpe functions and make file, as well as testing scripts.

Both students were discussing the strategy and used structures for the project beforehand and fixed the bugs afterwards.

## AI usage 
AI was used to help with consulatation on the algorithms and writing this README
Additionally testing script was developed 