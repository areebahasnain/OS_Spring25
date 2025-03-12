#!/bin/bash

# check if exactly 2 arguments are provided
if [ $# -ne 2 ]; then
	echo "Usage: $0 <num1. <num2>"
	exit 1
fi

# assigning arguments to variables
num1=$1
num2=$2

# multiplying the numbers
result=$((num1 * num2))

# print result
echo "The product of $num1 and $num2 is: $result"	
