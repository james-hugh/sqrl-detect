## 2026-02-17 - Authentication Bypass and Secure Logging
**Vulnerability:** Use of `strstr` for authentication allows substring bypasses. Insecure log file permissions could expose sensitive operation data.
**Learning:** Exact string matching (`strcmp`) is essential for authentication. `umask(0077)` ensures that log files are created with restrictive permissions (owner-only).
**Prevention:** Replaced `strstr` with `strcmp` for all authentication checks and implemented `umask(0077)` during log file creation to enforce Defense in Depth.
