# Sentinel's Journal

## 2026-04-08 - Secure Initialization and TOCTOU Prevention
**Vulnerability:** The application was creating a log directory without setting a restrictive `umask` and was using a `stat` check before `mkdir`, which is susceptible to a Time-of-check to time-of-use (TOCTOU) race condition. Additionally, the log files were created with default system permissions, potentially exposing "The Holy Scrolls of Truth" to other users on the system.
**Learning:** Even in simple CLI tools, system initialization should establish a secure environment. Relying on `stat()` before `mkdir()` is non-atomic and can be exploited.
**Prevention:** Use `umask(0077)` to enforce restrictive permissions for all subsequent file operations and call `mkdir()` directly, checking for `EEXIST` via `errno` to handle the case where the directory already exists securely and atomically.
