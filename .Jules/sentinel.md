# Sentinel's Journal - Critical Learnings Only

## 2026-03-25 - Hardened File Permissions and TOCTOU Prevention
**Vulnerability:** The application used `stat()` to check for directory existence before calling `mkdir()`, creating a Time-of-Check to Time-of-Use (TOCTOU) race condition. Additionally, default file permissions for logs were overly permissive.
**Learning:** Checking for file existence before creation is non-atomic and vulnerable to symlink attacks or race conditions where an attacker creates the path between the check and the action.
**Prevention:** Use atomic operations like `mkdir()` and check `errno` for `EEXIST`. Use `umask()` at process initialization to enforce a secure-by-default permission model for all subsequently created files and directories.
