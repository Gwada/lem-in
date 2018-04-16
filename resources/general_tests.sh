#!/bin/bash

invalid_input_tests()
{
	local counter=1
	local passed=0
	local failed=0

	clear
	printf "$COLOR\0TN_TEST // LEM_IN\n$END"
	printf "$COLOR\0INVALID INPUTS\n$END"

	mkdir -p tests/logs/
	while [ $counter -le $1 ]
		do
			./lem_in < tests/test$counter > tests/logs/test$counter 2>&1
			# if ! grep -r "ERROR" tests/logs/test$counter > /dev/null;
			# if ! diff -u tests/error tests/logs/test$counter > /dev/null;
			if grep -r "ERROR" tests/logs/test$counter > /dev/null;
				then
					rm tests/logs/test$counter
				else
					printf "$COLOR\0test$counter:   \tBOOM 🔥\n$END"
					failed=$((failed+1))
			fi
		counter=$((counter+1))
		done
	printf "$COLOR\n[DONE]\n$END"
	printf "$COLOR$(expr $1 - $failed)/$1 tests passed\n$END"
	printf "$COLOR\0Tip for debugging : diff -u valid testXXX | cat -e \n"

	read -p "Press enter to continue..."
}

valid_input_tests()
{
	local counter=1
	local passed=0
	local failed=0

	clear
	printf "$COLOR\0TN_TEST // LEM_IN\n$END"
	printf "$COLOR\0VALID INPUTS\n$END"
	
	mkdir -p tests/logs/
	while [ $counter -le $1 ]
		do
			./lem_in < tests/valid_tests/valid$counter > tests/logs/valid_test$counter 2>&1
			# if ! grep -r "ERROR" tests/logs/test$counter > /dev/null;
			# if ! diff -u tests/error tests/logs/test$counter > /dev/null;
			if grep -r "ERROR" tests/logs/valid_test$counter > /dev/null;
				then
					printf "$COLOR\0test$counter:   \tBOOM 🔥\n$END"
					failed=$((failed+1))
				else
					rm tests/logs/valid_test$counter
			fi
		counter=$((counter+1))
		done
	printf "$COLOR\n[DONE]\n$END"
	printf "$COLOR$(expr $1 - $failed)/$1 tests passed\n"

	read -p "Press enter to continue..."
}