## 2026-04-15 - Atomic Directory Creation and umask Hardening
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition in directory creation and permissive default file permissions.
**Learning:** Checking for directory existence with `stat` before calling `mkdir` creates a race window. Using `mkdir` directly and handling `EEXIST` via `errno` is atomic and secure. Additionally, process-wide `umask` ensures a secure-by-default posture for all filesystem operations.
**Prevention:** Always prefer atomic filesystem operations. Set a restrictive `umask` (e.g., `0077`) at application startup for security-sensitive CLI tools.
