## 2026-04-11 - Secure Log Directory Creation
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race conditions and insecure default file permissions when creating log directories.
**Learning:** Checking for directory existence before creation can lead to race conditions. Using `umask` ensures that any subsequently created files or directories have restricted permissions by default.
**Prevention:** Call `mkdir` directly and handle `EEXIST` via `errno`. Use `umask(0077)` to ensure log files are only readable by the owner.
