# Sentinel Journal - STNM3K

## 2025-02-26 - Authentication Bypass via Partial String Match
**Vulnerability:** The authentication system used `strstr()` to verify a "prayer" password, allowing attackers to bypass security by including the required phrase within a larger string (e.g., "I HATE GLORY BE" would pass a check for "GLORY BE").
**Learning:** Using substring search for authentication tokens or passwords is a critical logic flaw. User input from `fgets` often includes trailing newlines, which must be carefully stripped before exact comparison.
**Prevention:** Implement a robust `normalize_input` utility to trim whitespace and newlines, then use `strcmp` for exact authentication matches.

## 2025-02-26 - Insecure Default File Permissions
**Vulnerability:** The application created log files without setting a `umask` or specific file permissions, leading to potentially overly permissive (world-readable) security logs.
**Learning:** Default process `umask` can vary by environment. Security-sensitive applications must explicitly manage file creation masks.
**Prevention:** Call `umask(0077)` during system initialization to ensure all process-created files are restricted to the owner by default (Defense in Depth).
