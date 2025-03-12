#!/bin/bash

echo "Enter the filename:"
read filename

if [ -f "$filename" ]; then
	datetime=$(date "+%Y-%m-%d %H:%M:%S")
	
	echo "[$datetime] Appended by script" >> "$filename"
	
	echo "Date and Time appended to $filename"
else
	echo "Error: $filename not found!"
fi

