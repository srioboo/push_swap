#!/bin/bash

short_examples ()
{
	# set arguments
	ARG="4 67 3"; 
	# test
	./push_swap $ARG | wc -l
	# check result
	./push_swap $ARG | ./checker_linux $ARG
}

long_examples ()
{
	# set arguments
	ARG="4 67 3 87 23"; 
	# test
	./push_swap $ARG | wc -l
	# check result
	./push_swap $ARG | ./checker_linux $ARG

}

short_examples
# long_examples