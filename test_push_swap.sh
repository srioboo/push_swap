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
	echo -e "Checker: $CHECK, moves: $MOVES\n"
	./push_swap $ARG > /dev/null 2> errors.txt
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

check_string ()
{
	# set arguments
	ARG=$1
	check_base
}

#check_with_neg 100 3
#check_with_neg 10 5
# check 100 2
# check 100 3
# check 100 4 # pasa por 5 y no debería
check 100 5
check_string "12 98 46 71 16"
check_string "7 1 5 87 28"
check_string "6 59 98 33 22"
check_string "69 19 70 17 1"
check_string "69 19 70"
# check 100 100
# check_string "3 4 6 7"
# check_string "3 4 6 7"

# check 1000 500

#FICHERO=test_check.txt
#ARG="a"
# ARG="96 49 2 30 58"
# ./push_swap $ARG > /dev/null 2> test_check.txt
# if [ -s "$FICHERO" ];then
# 	while IFS= read -r line
# 	do
# 	if [[ $line == "Error" ]]; then
# 		printf "${GREEN}1.[OK] ${DEF_COLOR}\n";
# 	else
# 		printf "${RED}1.[KO] ${DEF_COLOR}\n";
# 		break
# 	fi
# 	done < test_check.txt
# else
# 	printf "${RED}1.[KO] ${DEF_COLOR}\n";
# fi
# echo $?