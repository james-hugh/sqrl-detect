## 2026-04-13 - Hardening System Initialization and File Permissions
**Vulnerability:** Insecure log directory creation (TOCTOU) and overly permissive default file permissions.
**Learning:** The application used a `stat` then `mkdir` pattern, which is vulnerable to TOCTOU race conditions. Additionally, it relied on the system's default `umask`, which often allows group and others to read generated log files.
**Prevention:** Use `umask(0077)` at the start of the application to ensure secure-by-default file permissions. Use atomic directory creation by calling `mkdir` directly and handling `EEXIST` via `errno`.
