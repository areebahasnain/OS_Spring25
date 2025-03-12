#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Usuage: $0 <directory_to_backup>"
	exit 1
fi

SOURCE_DIR=$1

if [ ! -d "SOURCE_DIR" ]; then
	echo "Error: DIrectory '$SOURCE_DIR' does not exist!"
	exit 1
fi

BACKUP_ROOT="backup"

DATE=$(date +"%Y-%m-%d_%H:%M:%S")

