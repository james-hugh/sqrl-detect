#!/bin/bash
# Comprehensive test script for STNM3K menu navigation

# Ensure binary is up to date
make clean && make > /dev/null 2>&1

# Test Authentication and Exit (Option 4)
echo "Running Test: Authentication and Exit..."
OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n4" | ./STNM3K)

if echo "$OUTPUT" | grep -q "Authentication successful" && echo "$OUTPUT" | grep -q "Cowardice detected"; then
    echo "✅ Authentication and Exit test passed."
else
    echo "❌ Authentication and Exit test failed."
    echo "Output was:"
    echo "$OUTPUT"
    exit 1
fi

# Test Pillow Fort Status (Option 2)
echo "Running Test: Pillow Fort Status..."
# 2 to enter, then Enter to return to menu, then 4 to exit
OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2\n\n4" | ./STNM3K)

if echo "$OUTPUT" | grep -q "PILLOW FORT STATUS REPORT"; then
    echo "✅ Pillow Fort Status test passed."
else
    echo "❌ Pillow Fort Status test failed."
    exit 1
fi

# Test Holy Scrolls (Option 3)
echo "Running Test: Holy Scrolls..."
# 3 to enter, then Enter to return to menu, then 4 to exit
OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n3\n\n4" | ./STNM3K)

if echo "$OUTPUT" | grep -q "READING THE HOLY SCROLLS OF TRUTH"; then
    echo "✅ Holy Scrolls test passed."
else
    echo "❌ Holy Scrolls test failed."
    exit 1
fi

echo "All tests passed!"
