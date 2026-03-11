## 2025-03-11 - Enforce Restricted File Permissions and Fix TOCTOU
**Vulnerability:** Default broad file permissions for log files and a TOCTOU (Time-of-Check to Time-of-Use) vulnerability in directory creation.
**Learning:** Standard C `mkdir` and `fopen` calls respect the process's `umask`. Without an explicit `umask` call, sensitive log files might be created with world-readable permissions. Additionally, checking for directory existence with `stat` before calling `mkdir` creates a race condition.
**Prevention:** Use `umask(0077)` early in the program initialization to ensure all subsequently created files/directories are owner-only. Attempt `mkdir` directly and handle the result to avoid TOCTOU race conditions.
