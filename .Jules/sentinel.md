## 2026-03-20 - Hardening Log Directory Initialization
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition in directory creation. Using `stat` followed by `mkdir` allows a window where an attacker could create a symbolic link, potentially leading to unauthorized file access or overwrites.
**Learning:** Checking for directory existence before creation is non-atomic and prone to race conditions.
**Prevention:** Use `mkdir` directly and check for `errno == EEXIST` to handle the case where the directory already exists atomically. Additionally, set a restrictive `umask(0077)` to ensure that any created logs have the least privilege by default.
