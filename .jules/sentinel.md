## 2026-02-21 - Authentication and File System Hardening
**Vulnerability:** Substring matching (`strstr`) in authentication logic allows bypass (e.g., "SOME GLORY BE OTHER").
**Learning:** Exact string matching (`strcmp`) combined with input normalization (`strcspn` to strip newlines) is essential for secure authentication. Using `umask(0077)` at process start ensures all subsequently created files and directories (like logs) are private by default.
**Prevention:** Always use exact matching for security tokens and set a restrictive umask in security-sensitive applications.
