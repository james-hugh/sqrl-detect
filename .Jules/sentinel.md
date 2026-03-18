# Sentinel Journal 🛡️

## 2026-03-12 - TOCTOU and Insecure Default Permissions
**Vulnerability:** The application was using a `stat()` followed by a `mkdir()` sequence to create the `logs/` directory, creating a Time-of-Check to Time-of-Use (TOCTOU) race condition where a malicious user could potentially place a symbolic link or another file at the `logs/` path between the check and the creation. Additionally, the process did not enforce a restrictive `umask`, potentially creating files with overly permissive defaults depending on the user's environment.
**Learning:** Checking for file existence before creation is inherently insecure in multi-user environments. Defensive security requires atomic operations and explicit permission management.
**Prevention:** Always use atomic creation calls (like `mkdir()` with `errno == EEXIST` handling) and explicitly set the process `umask` (e.g., `umask(0077)`) at startup to enforce defense-in-depth for all subsequent file system operations.
