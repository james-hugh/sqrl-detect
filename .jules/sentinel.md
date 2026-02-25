## 2026-02-25 - Secure Log Management and Input Handling
**Vulnerability:** Default file permissions could allow unauthorized users to read sensitive monitoring logs. Lack of error handling for system-critical directories could lead to silent failures.
**Learning:** Enforcing restrictive `umask` settings and explicitly checking system call return values ensures the application fails securely and maintains data confidentiality.
**Prevention:** Call `umask(0077)` at initialization and implement robust error checking for `mkdir` and other file operations.
