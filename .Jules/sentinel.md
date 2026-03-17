## 2026-03-12 - TOCTOU and Insecure Permissions Prevention
**Vulnerability:** Use of `stat()` followed by `mkdir()` creates a Time-of-Check to Time-of-Use (TOCTOU) race condition. Additionally, default file creation permissions were too permissive.
**Learning:** Checking for directory existence before creation is non-atomic and can be exploited. Not setting a restrictive `umask` allows the system to create files with world-readable permissions by default.
**Prevention:** Use `mkdir()` directly and check `errno == EEXIST` to handle the directory's existence atomically. Always set `umask(0077)` at the start of the application to ensure all subsequent file and directory creations are restricted to the owner by default.
