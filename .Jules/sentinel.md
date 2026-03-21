## 2026-03-21 - TOCTOU and Insecure File Permissions in STNM3K
**Vulnerability:** A Time-of-Check to Time-of-Use (TOCTOU) race condition was present in the log directory creation, and the application relied on default system umask, leading to world-readable log files.
**Learning:** Checking for directory existence with `stat` before `mkdir` creates a race window. Additionally, failing to explicitly set a restrictive `umask` for sensitive log files can lead to information exposure.
**Prevention:** Use `umask(0077)` to ensure all files/directories created by the process are private by default. Call `mkdir` directly and handle `EEXIST` to atomically ensure the directory exists without race conditions.
