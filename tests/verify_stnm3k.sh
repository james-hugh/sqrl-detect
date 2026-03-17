#!/bin/bash
# Basic verification for STNM3K features and UI

# Test Authentication and Menu Display
OUTPUT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n4" | ./STNM3K)

if [[ "$OUTPUT" == *"[SUCCESS] ✅"* ]]; then
    echo "✅ Authentication UI Success found."
else
    echo "❌ Authentication UI Success NOT found."
fi

if [[ "$OUTPUT" == *"--- MAIN MENU ---"* ]]; then
    echo "✅ Main Menu header found."
else
    echo "❌ Main Menu header NOT found."
fi

# Test Pillow Fort Feature
OUTPUT_FORT=$(echo -e "GLORY BE\nGLORY BE\nGLORY BE\n3\n\n4" | ./STNM3K)
if [[ "$OUTPUT_FORT" == *"--- PILLOW FORT STATUS REPORT ---"* ]]; then
    echo "✅ Pillow Fort report found."
else
    echo "❌ Pillow Fort report NOT found."
fi

# Test Permissions
./STNM3K <<'AUTH_EXIT'
GLORY BE
GLORY BE
GLORY BE
4
AUTH_EXIT

if [ -d "logs" ]; then
    PERM=$(stat -c "%a" logs)
    if [ "$PERM" == "700" ]; then
        echo "✅ logs directory has 700 permissions."
    else
        echo "❌ logs directory has $PERM permissions (expected 700)."
    fi
fi

echo "Basic verification complete."
