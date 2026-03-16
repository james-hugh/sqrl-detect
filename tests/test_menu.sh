#!/bin/bash
# Test the menu navigation and authentication
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2" | ./STNM3K > menu_test.log 2>&1
if grep -q "Authentication successful" menu_test.log && grep -q "Cowardice detected" menu_test.log; then
    echo "PASS: Menu test successful."
else
    echo "FAIL: Menu test failed."
    cat menu_test.log
    exit 1
fi
rm menu_test.log
