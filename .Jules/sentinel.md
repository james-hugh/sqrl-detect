## 2026-03-12 - Secure Directory Initialization
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition in directory creation. Using `stat` followed by `mkdir` allows an attacker to create a symlink between the check and the creation.
**Learning:** Checking for directory existence with `stat` before calling `mkdir` is non-atomic and prone to race conditions.
**Prevention:** Use an atomic `mkdir` call and check the return value/errno (e.g., `errno != EEXIST`) to handle existing directories safely while ensuring the operation remains atomic. Set restrictive `umask` (e.g., `0077`) before creation.
