## 2026-02-16 - Enhanced Log Security and Authentication

**Vulnerability:**
- Log files were previously created with default system permissions, potentially allowing unauthorized users to read sensitive security logs.
- Authentication used substring matching (`strstr`), which could be bypassed by providing a string containing "GLORY BE" but with additional unauthorized content.

**Learning:**
- Using `umask(0077)` during file creation ensures that sensitive logs are restricted to the owner only (0600), adhering to the principle of "Fail Securely".
- Exact string matching with `strcmp` and proper newline stripping is essential for robust authentication and command parsing.

**Prevention:**
- Always set explicit file permissions for sensitive data.
- Use exact matching for authentication tokens and critical system commands.
- Audit log all authentication attempts, both successful and failed.
