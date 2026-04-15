## 2026-04-15 - TOCTOU and Insecure File Permissions
**Vulnerability:** The application used `stat` followed by `mkdir` to initialize its log directory, creating a Time-of-Check to Time-of-Use (TOCTOU) race condition. Additionally, files were created with default system permissions, potentially exposing sensitive logs.
**Learning:** Checking for existence before creation is non-atomic and vulnerable to symlink attacks. Relying on default system permissions can lead to over-permissive data exposure.
**Prevention:** Call `mkdir` directly and handle `EEXIST` via `errno` for atomicity. Use `umask(0077)` to enforce restrictive (owner-only) permissions for all files and directories created by the process.
