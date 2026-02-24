## 2026-02-24 - Hardened File System and Audit Logging
**Vulnerability:** Default file permissions could allow unauthorized users to read sensitive logs. Lack of authentication logging makes it difficult to detect brute-force attempts.
**Learning:** `umask(0077)` ensures all files created by the process are only accessible by the owner. Explicit error handling for directory creation prevents the application from running in an insecure or broken state. Audit logs provide essential visibility into security events.
**Prevention:** Always set a restrictive `umask` at startup and log all authentication attempts (success and failure).
