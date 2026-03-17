#!/bin/bash

# Build the project
make clean && make

# Test Authentication Failure
echo "WRONG" | ./STNM3K | grep "INCORRECT PRAYER"
if [ $? -eq 0 ]; then
    echo "✅ Auth failure test passed"
else
    echo "❌ Auth failure test failed"
    exit 1
fi

# Run Engage Defenses briefly to generate log entries
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n1" | ./STNM3K > defense_init.log &
STNM3K_PID=$!
sleep 2
kill $STNM3K_PID

# Test Menu Options
# 2: View Holy Scrolls
# 3: Check Pillow Fort
# 4: Exit
# Using a heredoc to provide multiple inputs
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2\n\n3\n\n4" | ./STNM3K > test_output.log

grep "📜 HOLY SCROLLS OF TRUTH" test_output.log
if [ $? -eq 0 ]; then
    echo "✅ View Holy Scrolls test passed"
else
    echo "❌ View Holy Scrolls test failed"
fi

grep "🏰 PILLOW FORT STATUS REPORT" test_output.log
if [ $? -eq 0 ]; then
    echo "✅ Check Pillow Fort test passed"
else
    echo "❌ Check Pillow Fort test failed"
fi

grep "Cowardice detected" test_output.log
if [ $? -eq 0 ]; then
    echo "✅ Exit test passed"
else
    echo "❌ Exit test failed"
fi

# Test Engage Defenses output specifically
grep "SQUIRREL THREAT METER" defense_init.log
if [ $? -eq 0 ]; then
    echo "✅ Engage Defenses test passed"
else
    echo "❌ Engage Defenses test failed"
fi

# Verify Permissions
LOG_PERM=$(stat -c "%a" logs)
if [ "$LOG_PERM" == "700" ]; then
    echo "✅ logs/ directory permissions correct (700)"
else
    echo "❌ logs/ directory permissions incorrect ($LOG_PERM)"
fi
