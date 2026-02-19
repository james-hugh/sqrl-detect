## 2026-02-19 - Hardening Authentication and File Permissions
**Vulnerability:** Weak authentication using substring matching and insecure default file permissions (umask) could allow unauthorized access or local file tampering.
**Learning:** Exact string matching with `strcmp` after normalization with `strcspn` prevents authentication bypasses, and setting `umask(0077)` ensures that all created files are restricted to the owner by default.
**Prevention:** Always use exact matching for security-critical inputs and explicitly set a restrictive umask at the process entry point.
