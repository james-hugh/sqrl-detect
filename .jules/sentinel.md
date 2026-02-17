## 2026-02-17 - Strict Authentication and Secure Logging

**Vulnerability:** Weak authentication matching and insecure log file permissions. The application used `strstr` for password verification, allowing partial matches to pass, and created log files with default (potentially overly permissive) system permissions. Furthermore, authentication attempts were not audit-logged.

**Learning:** Substring matching for authentication is a common anti-pattern that can lead to easy bypasses. Secure-by-default principles should be applied to all file creations, especially logs containing sensitive security events.

**Prevention:** Always use strict string comparison (`strcmp`) for authentication after proper input sanitization. Enforce secure file permissions by setting an appropriate `umask` (e.g., `0077`) at the process level or specifically during sensitive file operations.
