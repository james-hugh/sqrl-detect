#!/bin/bash
# Clean up
rm -rf logs
# Run the app to create logs
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n1" | ./STNM3K &
APP_PID=$!
sleep 2
kill $APP_PID || true

# Check log directory permissions
LOG_DIR_PERMS=$(stat -c "%a" logs)
if [ "$LOG_DIR_PERMS" != "700" ]; then
    echo "FAIL: logs directory has insecure permissions: $LOG_DIR_PERMS (expected 700)"
    exit 1
fi

# Check log file permissions
LOG_FILE_PERMS=$(stat -c "%a" logs/holy_scrolls.txt)
if [ "$LOG_FILE_PERMS" != "600" ]; then
    echo "FAIL: logs/holy_scrolls.txt has insecure permissions: $LOG_FILE_PERMS (expected 600)"
    exit 1
fi

echo "PASS: Security permissions verified."
