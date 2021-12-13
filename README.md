# 42-push_swap
[![oabdalla's 42Project Score](https://badge42.herokuapp.com/api/project/oabdalla/push_swap)](https://github.com/JaeSeoKim/badge42)

***Description:***

This program will sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.
- The game is composed of 2 stacks named a and b.
- stack a can contain a random amount of negative and/or positive numbers with no duplicates. stack b will be used as an auxillary stack
- The goal is to sort stack a in ascending order using the following instructions
  - sa : swap a - swap the first 2 elements at the top of stack a.
  -  sb : swap b - swap the first 2 elements at the top of stack b.
  -  ss : sa and sb at the same time.
  -  pa : push a - take the first element at the top of b and put it at the top of a.
  -  pb : push b - take the first element at the top of a and put it at the top of b.
  -  ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  -  rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  -  rr : ra and rb at the same time.
  -  rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
  -  rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
  -  rrr : rra and rrb at the same time.

***Objectives:***
- Sorting algorithms
- Battery concept and handling elements
- Algorithm implementation

***Skills:***
- Rigor
- Imperative programming
- Unix
- Algorithms & AI

***Usage:***
```
git clone
make push_swap
./push_swap [ list of integer values ]
```
***Sorting Stats:***
- list of 3 numbers :                        list of 5 numbers :
  -  maximum instructions      2               maximum instructions     12 
  -  minimum instructions      0                minimum instructions      5
  -  average of 100 runs       1                average of 100 runs       8

- list of 5 numbers :
  -  maximum instructions     12 
  -  minimum instructions      5
  -  average of 100 runs       8
- list of 100 numbers :
  -  maximum instructions    927 
  -  minimum instructions    927
  -  average of 100 runs     927
- list of 500 numbers :
  -  maximum instructions   5771 
  -  minimum instructions   5771
  -  average of 100 runs    5771

***Preview:***
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```
![screen-gif](./so_long.gif)
