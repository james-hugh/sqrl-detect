## 2026-04-12 - Secure Directory Initialization and Permissions
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race conditions and overly permissive default file/directory permissions.
**Learning:** Checking for directory existence before creation can lead to race conditions. Calling `mkdir` directly and handling the `EEXIST` error via `errno` is more robust. Additionally, setting a restrictive `umask(0077)` at startup ensures that all subsequently created files and directories have secure default permissions.
**Prevention:** Always use atomic file operations and set a restrictive `umask` for applications handling sensitive data or logs.
