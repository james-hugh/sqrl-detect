#!/bin/bash
set -e

# Cleanup previous artifacts
rm -rf logs
make clean
make

# Run the program with mocked input to trigger log creation
# Recite "GLORY BE" three times, then engage defenses (1), then wait for it to start and kill it
echo -e "GLORY BE\nGLORY BE\nGLORY BE\n1" | timeout 2 ./STNM3K || true

# Check permissions of the logs directory
LOGS_PERM=$(stat -c "%a" logs)
if [ "$LOGS_PERM" != "700" ]; then
    echo "❌ ERROR: logs directory has insecure permissions: $LOGS_PERM (expected 700)"
    exit 1
fi
echo "✅ logs directory has secure permissions (700)"

# Check permissions of the log file
LOG_FILE="logs/holy_scrolls.txt"
if [ ! -f "$LOG_FILE" ]; then
    echo "❌ ERROR: $LOG_FILE was not created"
    exit 1
fi

FILE_PERM=$(stat -c "%a" "$LOG_FILE")
if [ "$FILE_PERM" != "600" ]; then
    echo "❌ ERROR: $LOG_FILE has insecure permissions: $FILE_PERM (expected 600)"
    exit 1
fi
echo "✅ $LOG_FILE has secure permissions (600)"

echo "🛡️ SECURITY VERIFICATION PASSED"
