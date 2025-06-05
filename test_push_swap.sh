#!/bin/bash

clear
make re

short_examples ()
{
	# set arguments
	ARG="4 67 3";
	# main
	# echo -e "Launching './push_swap $ARG'"
	# ./push_swap $ARG
	# test
	echo -e "\nLaunching './push_swap $ARG | wc -l'"
	./push_swap $ARG | wc -l
	# check result
	echo -e "\nLaunching './push_swap $ARG | ./checker_linux $ARG'"
	./push_swap $ARG | ./checker_linux $ARG
}

long_examples ()
{
	# set arguments
	ARG="4 67 3 87 23";
	# main
	# echo -e "Launching './push_swap $ARG'"
	# ./push_swap $ARG
	# test
	echo -e "\nLaunching './push_swap $ARG | wc -l'"
	./push_swap $ARG | wc -l
	# check result
	echo -e "\nLaunching './push_swap $ARG | ./checker_linux $ARG'"
	./push_swap $ARG | ./checker_linux $ARG

}

other_examples ()
{
	# set arguments
	ARG=$(shuf -i 1-$1 -n $2 | tr '\n' ' ');
	# main
	# echo -e "Launching './push_swap $ARG'"
	# ./push_swap $ARG
	# test
	echo -e "\nLaunching './push_swap $ARG | wc -l'"
	./push_swap $ARG | wc -l
	# check result
	echo -e "\nLaunching './push_swap $ARG | ./checker_linux $ARG'"
	./push_swap $ARG | ./checker_linux $ARG
}

other_examples_with_neg ()
{
	# set arguments
	ARG=$(seq -$1 $1| shuf -n $2 | tr '\n' ' ');
	# main
	# echo -e "Launching './push_swap $ARG'"
	# ./push_swap $ARG
	# test
	echo -e "\nLaunching './push_swap $ARG | wc -l'"
	./push_swap $ARG | wc -l
	# check result
	echo -e "\nLaunching './push_swap $ARG | ./checker_linux $ARG'"
	./push_swap $ARG | ./checker_linux $ARG

}

# short_examples
# long_examples
other_examples 10 100
other_examples 1000 100
other_examples_with_neg 30 10