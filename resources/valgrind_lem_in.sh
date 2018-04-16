#!/bin/bash

VALGRIND_LOGS_DIR="valgrind_logs"
VALGRIND_LOGS_FILENAME="vlg_"

check_one_valgrind()
{
	local STORAGE_PATH=$VALGRIND_LOGS_DIR"/"$VALGRIND_LOGS_FILENAME"_test"$1
	local TESTS_PATH=$TESTS_ABSOLUTE_PATH/test$1

	$HOME/.brew/Cellar/valgrind/3.13.0/bin/valgrind --leak-check=full --log-file="$STORAGE_PATH" ./lem_in < tests/test$1 > /dev/null
	local definitely_lb=$(cat $STORAGE_PATH | grep "definitely lost: " | cut -d " " -f7)
	local indirectly_lb=$(cat $STORAGE_PATH | grep "indirectly lost: " | cut -d " " -f7)
	if [ "$definitely_lb" != "0" ] || [ "$indirectly_lb" != "0" ]
	then
		printf "\ntest$1:   \t$definitely_lb bytes definitely lost, $indirectly_lb bytes indirectly lost 💦"
		# say boom
	else
		printf "$COLOR.$END"
	fi
}

check_one_valgrind_valid()
{
	local STORAGE_PATH=$VALGRIND_LOGS_DIR"/"$VALGRIND_LOGS_FILENAME"_valid"$1
	local TESTS_PATH=$TESTS_ABSOLUTE_PATH/test$1

	$HOME/.brew/Cellar/valgrind/3.13.0/bin/valgrind --leak-check=full --log-file="$STORAGE_PATH" ./lem_in < tests/valid_tests/valid$1 > /dev/null
	local definitely_lb=$(cat $STORAGE_PATH | grep "definitely lost: " | cut -d " " -f7)
	local indirectly_lb=$(cat $STORAGE_PATH | grep "indirectly lost: " | cut -d " " -f7)
	if [ "$definitely_lb" != "0" ] || [ "$indirectly_lb" != "0" ]
	then
		printf "\nvalid$1:   \t$definitely_lb bytes definitely lost, $indirectly_lb bytes indirectly lost 💦"
		# say boom
	else
		printf "$COLOR.$END"
	fi
}

check_valgrind()
{
	local VERSION=$(ls $HOME/.brew/Cellar | grep valgrind)
	local c=1

	clear
	printf "$COLOR\0TN_TEST // LEM_IN\n$END"
	printf "$COLOR\0MEMORY LEAKS\n$END"
	if [ $VERSION ]
	then
		rm -rf $VALGRIND_LOGS_DIR
		mkdir -p $VALGRIND_LOGS_DIR
		printf "$COLOR\0INVALID INPUTS\n$END"
		while [ $c -le $1 ]
		do
			check_one_valgrind $c
			let "c++"
		done
		local c=1
		printf "$COLOR\0\nVALID INPUTS\n$END"
		while [ $c -le $2 ]
		do
			check_one_valgrind_valid $c
			let "c++"
		done
	else
		printf "$COLOR\0Valgrind is not installed on this machine.\nTo install it, run the following command:\nbrew update && brew install valgrind && alias valgrind=\"~/.brew/bin/valgrind\"$END"
	fi
	rm -rf lem_in.dSYM
	printf "$COLOR\n[LEAKS DONE]\n$END"
}
