#!/bin/bash

# Test authentication and menu navigation
echo "Testing STNM3K..."

# Input sequence:
# 3x GLORY BE (Authentication)
# 2 (Fort Status)
# Enter (Return from Fort Status)
# 3 (Holy Scrolls)
# Enter (Return from Holy Scrolls)
# 4 (Exit)
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2\n\n3\n\n4" | ./STNM3K > test_output.log 2>&1

if grep -q "Authentication successful" test_output.log; then
    echo "✅ Authentication successful"
else
    echo "❌ Authentication failed"
    exit 1
fi

if grep -q "PILLOW FORT STATUS REPORT" test_output.log; then
    echo "✅ Fort Status display works"
else
    echo "❌ Fort Status display failed"
    exit 1
fi

if grep -q "THE HOLY SCROLLS OF TRUTH" test_output.log; then
    echo "✅ Holy Scrolls display works"
else
    echo "❌ Holy Scrolls display failed"
    exit 1
fi

if grep -q "Cowardice detected" test_output.log; then
    echo "✅ Persistent menu and exit work"
else
    echo "❌ Persistent menu or exit failed"
    exit 1
fi

echo "All tests passed!"
