#!/bin/bash

clear
make re

check_base ()
{
	# main
	echo -e "  \nCheking 'push_swap with $2 values'"
	echo -e " [ $ARG]'"
	MOVES=$(./push_swap $ARG | wc -l)
	CHECK=$(./push_swap $ARG | ./checker_linux $ARG)
	# check result
	echo -e "Checker: $CHECK, moves: $MOVES"
}

check ()
{

	# set arguments
	ARG=$(shuf -i 1-$1 -n $2 | tr '\n' ' ');
	check_base

}

check_with_neg ()
{
	# set arguments
	ARG=$(seq -$1 $1| shuf -n $2 | tr '\n' ' ');
	check_base
}

#check_with_neg 100 3
#check_with_neg 10 5
check 100 3
# check 100 5
check 100 100
# check 1000 500