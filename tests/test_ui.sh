#!/bin/bash

echo "Building STNM3K..."
make clean && make

echo "Verifying Authentication UI..."
# Test successful authentication
SUCCESS_OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2" | ./STNM3K)
if [[ "$SUCCESS_OUTPUT" == *"SUCCESS"* ]]; then
    echo "✅ Success feedback verified."
else
    echo "❌ Success feedback NOT found!"
    exit 1
fi

# Test failed authentication
FAILURE_OUTPUT=$(echo -e "WRONG PRAYER" | ./STNM3K)
if [[ "$FAILURE_OUTPUT" == *"FAILURE"* ]]; then
    echo "✅ Failure feedback verified."
else
    echo "❌ Failure feedback NOT found!"
    exit 1
fi

echo "Verifying Main Menu UI..."
if [[ "$SUCCESS_OUTPUT" == *"MAIN MENU"* ]]; then
    echo "✅ Menu header verified."
else
    echo "❌ Menu header NOT found!"
    exit 1
fi

if [[ "$SUCCESS_OUTPUT" == *"🕹️"* ]]; then
    echo "✅ Engage emoji verified."
else
    echo "❌ Engage emoji NOT found!"
    exit 1
fi

if [[ "$SUCCESS_OUTPUT" == *"💀"* ]]; then
    echo "✅ Exit emoji verified."
else
    echo "❌ Exit emoji NOT found!"
    exit 1
fi

echo "UI Verification Passed!"
