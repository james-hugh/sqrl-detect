#!/bin/bash

# ANSI Color codes for grep
# Note: In bash, we can use \x1b or \e or \033. grep -P might be needed for \x1b, or just match the raw bytes.
# We'll use a more robust way to check for the escape sequences.

# Run STNM3K with authentication and immediate exit
# We use '2' to select EXIT (COWARDLY) from the main menu
OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2" | ./STNM3K)

echo "--- START OUTPUT ---"
echo "$OUTPUT"
echo "--- END OUTPUT ---"

# Check for text content
echo "Checking for COMMAND CENTER header..."
echo "$OUTPUT" | grep -q "\-\-\- COMMAND CENTER \-\-\-" || { echo "FAILED: Header missing"; exit 1; }

echo "Checking for ENGAGE DEFENSES option..."
echo "$OUTPUT" | grep -q "\[1\] 🛡️  ENGAGE DEFENSES" || { echo "FAILED: Option 1 missing or formatted incorrectly"; exit 1; }

echo "Checking for EXIT (COWARDLY) option..."
echo "$OUTPUT" | grep -q "\[2\] 🏃 EXIT (COWARDLY)" || { echo "FAILED: Option 2 missing or formatted incorrectly"; exit 1; }

# Check for color codes using their octal representation which is safer for grep
# \x1B[33m is \033[33m
echo "Checking for Yellow color code..."
echo "$OUTPUT" | grep -q $'\033\[33m' || { echo "FAILED: Yellow color code missing"; exit 1; }

echo "Checking for Green color code..."
echo "$OUTPUT" | grep -q $'\033\[32m' || { echo "FAILED: Green color code missing"; exit 1; }

echo "Checking for Red color code..."
echo "$OUTPUT" | grep -q $'\033\[31m' || { echo "FAILED: Red color code missing"; exit 1; }

echo "Checking for RESET code..."
echo "$OUTPUT" | grep -q $'\033\[0m' || { echo "FAILED: Reset color code missing"; exit 1; }

echo "SUCCESS: UI changes verified!"
