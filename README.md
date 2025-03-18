# push_swap

Project to learn about algorithms by sorting stacks of integers

Order two integers, you have two stack of values and a bunch of functions to manipulate both stacks.

You must create a C program that calculate and show a little protam with the instructions of the "Push Swap" lenguage, that order the numbers receibed as arguments.

Name: push_swap
archives: Makefile, '*.h', '*.c'
Makefile: NAME, all, clean, fclean, re
Arguments: stack a: a list of integers
Allowed functions:
    - read, write, malloc, free, exit
    - ft_printf and equivalente functions
Libft: yes
Description: order stacks

```shell
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

## Operations

Operations description and text write in the output once the operation is done

1. **swap**: swap the first 2 elements at the top of the stack a 
   - sa: swap a
   - sb: swap b
   - ss: swap a and b
2. **push**: takes the first element on top on list_b and puts in on list_a
   - pa: push a
   - pb: pusb b, same as previos opertation for b
3. **rotate**: swift elements one position, first element become last.
   - ra: rotate a, shift all the elements up ope position, firs element become last
   - rb: rotate b, same as previos for b
   - rr: rotate a and b
4. **rotate reverse**: swift elements one position, last element become first.
   - rra: reverse rotate, as rotate but in the other direction
   - rrb: reverse robate for b
   - rrr: reverse rotate all

## Test with checker

```shell
# count operations result
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# check result
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```