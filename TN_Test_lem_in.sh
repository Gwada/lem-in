#!/bin/bash

COLOR='\x1b[38;5;220m'
END='\x1b[0m'
n=138
p=27

source resources/general_tests.sh
source resources/valgrind_lem_in.sh

sh resources/animation.sh

clear
echo "$COLOR\0TN_TEST // LEM_IN\n$END"
sleep 1

make

echo "$COLOR\0Compiling...\n$END"

mv "lem-in" lem_in

echo "$COLOR\0Compiling done.\n$END"

invalid_input_tests $n

valid_input_tests $p

check_valgrind $n $p

mv lem_in "lem-in"

echo "$COLOR\0[ALL DONE]$END"
