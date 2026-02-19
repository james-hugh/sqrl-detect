## 2026-02-19 - Hardening Authentication and Log Security
**Vulnerability:** Substring matching (strstr) in authentication allowed for potential bypasses. Default file permissions could expose sensitive logs to other users.
**Learning:** Exact string matching (strcmp) after newline stripping is essential for secure authentication. Global process umask(0077) ensures all created files are secure by default.
**Prevention:** Replaced strstr with strcmp for authentication and added umask(0077) at process start. Implemented audit logging for all authentication attempts.
