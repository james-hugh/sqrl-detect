#!/bin/bash

# tests/test_menu.sh - Automated verification for STNM3K UI improvements

# Ensure binary is built
make clean && make

# Test Authentication Success and Menu rendering
echo "Testing successful authentication and menu..."
OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2" | ./STNM3K)

if echo "$OUTPUT" | grep -q "\[SUCCESS\] ✅"; then
    echo "PASS: Found success message with emoji."
else
    echo "FAIL: Success message or emoji missing."
    exit 1
fi

if echo "$OUTPUT" | grep -q -- "--- MAIN MENU ---"; then
    echo "PASS: Found main menu header."
else
    echo "FAIL: Main menu header missing."
    exit 1
fi

if echo "$OUTPUT" | grep -q "🕹️  ENGAGE DEFENSES"; then
    echo "PASS: Found Engage Defenses option with emoji."
else
    echo "FAIL: Engage Defenses emoji missing."
    exit 1
fi

if echo "$OUTPUT" | grep -q "💀  EXIT (COWARDLY)"; then
    echo "PASS: Found Exit option with emoji."
else
    echo "FAIL: Exit emoji missing."
    exit 1
fi

# Test Authentication Failure
echo "Testing authentication failure..."
FAILURE_OUTPUT=$(echo -e "WRONG PRAYER" | ./STNM3K)

if echo "$FAILURE_OUTPUT" | grep -q "\[FAILURE\] ❌"; then
    echo "PASS: Found failure message with emoji."
else
    echo "FAIL: Failure message or emoji missing."
    exit 1
fi

echo "All UI tests passed successfully!"
