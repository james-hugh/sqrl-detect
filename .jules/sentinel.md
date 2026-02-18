## 2026-02-18 - Authentication and Permission Hardening
**Vulnerability:** Use of `strstr` for authentication allowed potential bypasses. Default file permissions were too loose.
**Learning:** Exact string matching with `strcmp` (after stripping newlines) is essential for security. Audit logging provides critical visibility into access attempts.
**Prevention:** Always use `strcmp` for passwords/prayers. Set a restrictive `umask(0077)` at process startup.
