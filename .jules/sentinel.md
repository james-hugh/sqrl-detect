## 2026-04-15 - Atomic Directory Creation and Secure Permissions
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race conditions when checking for directory existence before creation.
**Learning:** Calling `mkdir` directly and handling `EEXIST` via `errno` is more robust and secure than checking with `stat` first. Additionally, setting `umask(0077)` ensures sensitive directories and files (like logs) are created with restricted permissions by default.
**Prevention:** Use atomic system calls and explicit `umask` settings for security-critical file operations.
