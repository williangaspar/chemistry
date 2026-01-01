#!/bin/bash

# Set the source and output file names
SRC="main.cpp chemistry.cpp"
OUT="app"

# Compile the C++ program
g++ -std=c++17 -Wall -g $SRC -o "$OUT"
if [ $? -ne 0 ]; then # If $? (the exit status of the last command) is not 0, compilation failed
    echo "Compilation failed."
    exit 1
fi

# If the first argument is "run", execute the program
if [ "$1" == "run" ]; then
shift # remove "run" from arguments
    ./"$OUT" "$@"
fi