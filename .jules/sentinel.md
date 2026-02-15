## 2026-02-15 - [Log Hardening and Auth Strengthening]
**Vulnerability:** Default file creation permissions and substring-based authentication bypass.
**Learning:** `fopen` with "a" or "w" creates files with permissions based on the process's umask, which is often too permissive (e.g., 0644). Substring matching for passwords (`strstr`) allows attackers to bypass checks by appending extra data to a valid password.
**Prevention:** Use `umask(0077)` before creating sensitive files like logs to ensure 0600 permissions. Use `strcmp` with sanitized input for exact matching of credentials. Always include audit logging for authentication events.
