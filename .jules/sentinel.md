## 2025-02-23 - Hardening File Permissions and Input Validation
**Vulnerability:** The application used insecure default file permissions (0644) for logs and loose string matching (`strstr`) for authentication and command processing.
**Learning:** In C CLI applications, relying on default `umask` and loose substring matching can lead to unauthorized access to logs and authentication bypasses. `umask(0077)` ensures all created files are secure by default.
**Prevention:** Always set an explicit `umask` at process startup and use strict string comparison (`strcmp`) with normalized input for security-critical checks.
