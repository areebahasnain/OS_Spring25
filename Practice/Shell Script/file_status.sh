#!/bin//bash

echo "Enter file or directory name: "
read path

if [ -e "$path" ]; then
	if [ -f "$path" ]; then
		echo "'$path' is a regular file."
	elif [ -d "$path" ]; then
		echo "'$path' is a directory."
	else
		echo "'$path' exists but is neither a file not directory."
	fi
	
	if [ -r "$path" ]; then
        	echo "It has read permissions."
    	fi
    	if [ -w "$path" ]; then
        	echo "It has write permissions."
    	fi
    	if [ -x "$path" ]; then
        	echo "It has execute permissions."
    	fi
else
    echo "Error: '$path' does not exist!"
fi
				
