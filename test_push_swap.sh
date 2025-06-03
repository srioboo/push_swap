#!/bin/bash

clear
make re

short_examples ()
{
	# set arguments
	ARG="4 67 3";
	# main
	echo -e "Launching './push_swap $ARG'"
	./push_swap $ARG
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
	# test
	./push_swap $ARG | wc -l
	# check result
	./push_swap $ARG | ./checker_linux $ARG

}

short_examples
# long_examples