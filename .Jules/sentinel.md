# Sentinel Journal

## 2026-03-12 - TOCTOU and Insecure Log Permissions
**Vulnerability:** The application uses a `stat` check followed by `mkdir` to create the log directory, which is a classic Time-of-Check to Time-of-Use (TOCTOU) race condition. Additionally, logs were created with default system permissions (umask dependent), potentially exposing sensitive "holy scrolls" to other users on the system.
**Learning:** Checking for file existence before creation is risky in multi-user environments. Using `umask` at the start of the process provides a safety net for all subsequent file operations.
**Prevention:** Always use atomic operations for file creation (like `mkdir` directly and checking for `EEXIST`) and set a restrictive `umask` (e.g., `0077`) to ensure default secure permissions.
