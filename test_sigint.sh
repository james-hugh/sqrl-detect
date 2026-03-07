#!/bin/bash
./STNM3K <<EOF &
GLORY BE
GLORY BE
GLORY BE
1
EOF
APP_PID=$!
sleep 3
kill -INT $APP_PID
sleep 1
if ps -p $APP_PID > /dev/null; then
    echo "Process still running after SIGINT (Expected behavior as it should return to main menu loop)"
    kill -9 $APP_PID 2>/dev/null
    exit 0
else
    echo "Process terminated unexpectedly after SIGINT"
    exit 1
fi
