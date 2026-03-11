#!/bin/bash
# Updated verification script for STNM3K menu

echo "Testing authentication and exit..."
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n3" | ./STNM3K | grep -E "Authentication successful|Cowardice detected"

echo "Testing View Holy Scrolls..."
# Create a dummy log if it doesn't exist
mkdir -p logs
echo "TEST LOG ENTRY" > logs/holy_scrolls.txt
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n2\n3" | ./STNM3K | grep "TEST LOG ENTRY"

echo "Testing Invalid Command..."
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n99\n3" | ./STNM3K | grep "Invalid command"
