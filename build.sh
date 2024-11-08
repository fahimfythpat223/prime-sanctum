#!/bin/bash

# Set the output executable name
OUTPUT="prime-sanctum"

# Compile the project with g++, including the headers directory
g++ -o $OUTPUT bcrypt.cpp blowfish.cpp prime-sanctum.cpp encryption.cpp -I headers

# Check if g++ returned an error
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
else
    echo "Compilation succeeded. Executable created: $OUTPUT"
fi
