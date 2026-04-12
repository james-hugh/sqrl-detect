## 2026-04-12 - TOCTOU Prevention and Secure Umask
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition during directory creation and insecure default file permissions.
**Learning:** Checking for directory existence before creation can be subverted; calling `mkdir` directly and handling `EEXIST` is atomic and safer. Additionally, setting a restrictive `umask` (e.g., `0077`) ensures all created files and directories are private by default.
**Prevention:** Use atomic system calls for resource creation and enforce strict default permissions via `umask`.
