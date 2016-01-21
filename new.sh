#!/bin/bash

# Test for parameters
if [[ $# -ne 1 ]]
then
	echo "Usage: $0 <project_name>"
	exit
fi

# make the new directory
if [[ ! -d $1 ]]
then
	echo Creating directory $1
	mkdir $1

	# Copy the files to the new directory
	echo Copying skeleton files to new directory $1
	cp .skel/* $1
else
	echo Directory $1 already exists
fi
