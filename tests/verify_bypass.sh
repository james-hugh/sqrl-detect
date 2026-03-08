#!/bin/bash

# Build the application
make clean
make

# Test authentication bypass
# Inputting a substring that contains the "sacred prayer" should currently work
echo -e "I HATE GLORY BE\nI HATE GLORY BE\nI HATE GLORY BE\n2" | ./STNM3K > output.log 2>&1

if grep -q "Authentication successful" output.log; then
    echo "BYPASS DETECTED: Successfully authenticated with 'I HATE GLORY BE'"
    exit 0
else
    echo "BYPASS FAILED: Could not authenticate with 'I HATE GLORY BE'"
    exit 1
fi
