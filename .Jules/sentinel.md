## 2026-04-07 - Restrictive File Permissions and Atomic Directory Creation
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) and Insecure Default File Permissions.
**Learning:** Checking for directory existence with `stat()` before `mkdir()` creates a race condition. Also, failing to set an explicit `umask` leaves log file permissions dependent on the user's environment.
**Prevention:** Use atomic system calls like `mkdir()` and check `errno == EEXIST`. Explicitly set `umask(0077)` to enforce the principle of least privilege for all files created by the application.
