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
	# ./push_swap $ARG  
}

check_pos_only ()
{
	# set arguments
	ARG=$(shuf -i 1-$1 -n $2 | tr '\n' ' ');
	check_base
}

check ()
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

# ARG=$(cat push_swap_tester/trace_loop/test_case_1.txt | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG

# check 100 2
# check 100 3
# check 100 5
# check 100 4
# check 100 10
# check 100 15
# check 100 100

# check_string "12 98 46 71 16"
# check_string "7 1 5 87 28"
# check_string "6 59 98 33 22"
# check_string "69 19 70 17 1"
# check_string "69 19 70"
# check_string "3 4 6 7"
# check_string "3 4 6 7"
check_string "-19 40 24 -4 85 44 -17 -75 -77 93 -16 98 30 -12 -79 55 67 -9 -91 -65 -28 -45 46 87 -43 7 100 -69 -33 -26 23 -2 -25 -98 75 -84 -67 -44 -60 15 0 32 -35 -74 -21 -80 61 38 37 -52 81 91 9 -78 12 -62 48 68 27 42 4 -54 36 63 -50 -59 -8 49 74 -58 -87 11 22 51 -51 -6 90 -53 83 73 -48 -81 -90 -68 54 10 -30 60 -93 19 -40 -38 -23 -96 77 17 5 -3 -27 -95"
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