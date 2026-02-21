## 2026-02-21 - Securing CLI Authentication and File System Integrity
**Vulnerability:** Substring matching (`strstr`) in authentication checks allows for bypasses with unintended inputs, and lack of explicit file permission masking (`umask`) can lead to sensitive logs being world-readable.
**Learning:** Defense in Depth requires both robust input validation (exact matching with `strcmp`) and secure environment defaults (setting `umask` at process start).
**Prevention:** Always use exact string comparison for authentication and restrict process-wide file creation permissions using `umask(0077)`.
