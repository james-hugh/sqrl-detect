#!/bin/bash
rm -rf logs
make clean && make
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n1\n" | ./STNM3K > /dev/null 2>&1 &
SLEEP_PID=$!
sleep 2
kill $SLEEP_PID 2>/dev/null || true

echo "Permissions for logs directory:"
ls -ld logs
echo "Permissions for holy_scrolls.txt:"
ls -l logs/holy_scrolls.txt
