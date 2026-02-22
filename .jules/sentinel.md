## 2026-02-22 - Hardened Authentication and System Initialization
**Vulnerability:** Substring matching (`strstr`) in authentication and loose file permissions for logs.
**Learning:** Using `strcmp` after safe input normalization prevents authentication bypasses that might occur with partial matches. Setting a strict `umask(0077)` ensures that all files created by the process (like logs) are only accessible by the owner.
**Prevention:** Always use exact string matching for security-critical inputs and enforce the Principle of Least Privilege for filesystem artifacts.
