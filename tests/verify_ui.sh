#!/bin/bash

# Verification script for STNM3K UI improvements

# Ensure binary is compiled
make clean && make

# Test 1: Successful Authentication and Menu
echo "Test 1: Successful Authentication and Menu"
output=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2" | ./STNM3K)

if echo "$output" | grep -q "\[SUCCESS\] Prayer accepted."; then
    echo "✅ [SUCCESS] label found in authentication."
else
    echo "❌ [SUCCESS] label NOT found in authentication."
    exit 1
fi

if echo "$output" | grep -q "STNM3K MAIN MENU"; then
    echo "✅ Main Menu header found."
else
    echo "❌ Main Menu header NOT found."
    exit 1
fi

if echo "$output" | grep -q "🕹️ ENGAGE DEFENSES"; then
    echo "✅ 'Engage Defenses' emoji found."
else
    echo "❌ 'Engage Defenses' emoji NOT found."
    exit 1
fi

if echo "$output" | grep -q "💀 EXIT"; then
    echo "✅ 'Exit' emoji found."
else
    echo "❌ 'Exit' emoji NOT found."
    exit 1
fi

# Test 2: Failed Authentication
echo "Test 2: Failed Authentication"
output_fail=$(echo -e "WRONG\n" | ./STNM3K)

if echo "$output_fail" | grep -q "\[FAILURE\] Incorrect invocation."; then
    echo "✅ [FAILURE] label found in failed authentication."
else
    echo "❌ [FAILURE] label NOT found in failed authentication."
    exit 1
fi

echo "All UI verification tests passed!"
