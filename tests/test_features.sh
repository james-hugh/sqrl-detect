#!/bin/bash
set -e

echo "--- Building STNM3K ---"
make clean && make

echo "--- Testing Main Menu and EXIT ---"
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n4" | ./STNM3K | grep "Cowardice detected"

echo "--- Testing VIEW HOLY SCROLLS ---"
# Trigger a log entry first by engaging defenses briefly (simulated input might be tricky for loop)
# But we can check if the menu option is there and it doesn't crash
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2\n\n4" | ./STNM3K | grep "THE HOLY SCROLLS OF TRUTH"

echo "--- Testing CHECK PILLOW FORT ---"
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n3\n\n4" | ./STNM3K | grep "PILLOW FORT COMMAND CENTER STATUS"

echo "--- Testing Security Hardening (Log Dir Permissions) ---"
# Clean up logs first to test creation
rm -rf logs
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n4" | ./STNM3K > /dev/null
PERMS=$(stat -c "%a" logs)
if [ "$PERMS" == "700" ]; then
    echo "SUCCESS: Log directory has restrictive 700 permissions."
else
    echo "FAILURE: Log directory has $PERMS permissions."
    exit 1
fi

echo "--- ALL TESTS PASSED ---"
