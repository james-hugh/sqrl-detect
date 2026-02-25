## 2026-02-25 - Security Hardening and Audit Logging
**Vulnerability:** Loose input validation using `strstr` and permissive default file permissions for logs.
**Learning:** Using `strstr` for command matching allows for unintended partial matches (e.g., "10" matches "1"). Default file creation permissions can leak sensitive log data to other users on a multi-user system.
**Prevention:** Implement `normalize_input` to trim whitespace and use `strcasecmp`/`strcmp` for exact matching. Use `umask(0077)` at system initialization to ensure all process-created files are owner-only. Add comprehensive audit logging for sensitive operations like authentication.
