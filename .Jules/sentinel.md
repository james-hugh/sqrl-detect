## 2026-03-12 - TOCTOU and Insecure Permissions Prevention
**Vulnerability:** Use of `stat()` followed by `mkdir()` creates a Time-of-Check to Time-of-Use (TOCTOU) race condition. Additionally, default directory permissions could be too permissive.
**Learning:** Checking for directory existence before creation can be exploited if an attacker creates the directory (or a symlink) between the check and the creation.
**Prevention:** Use `umask()` to set restrictive default permissions (e.g., `0077`) and use an atomic `mkdir()` call, then check `errno` for `EEXIST` to handle existing directories safely.
