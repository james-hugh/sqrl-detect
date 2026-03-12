# SENTINEL'S JOURNAL - CRITICAL LEARNINGS ONLY

## 2026-03-12 - Secure File Creation and TOCTOU
**Vulnerability:** Use of `stat()` followed by `mkdir()` creates a Time-of-Check to Time-of-Use (TOCTOU) race condition. Additionally, default `umask` can lead to insecure file permissions for sensitive logs.
**Learning:** Checking for directory existence before creating it is redundant and potentially dangerous if an attacker can create the directory between the check and the creation.
**Prevention:** Use `umask()` to enforce strict permissions globally within the process and call `mkdir()` directly, handling `EEXIST` error if the directory already exists.
