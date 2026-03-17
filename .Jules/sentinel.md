## 2026-03-12 - Insecure Default File Permissions
**Vulnerability:** Application logs (`logs/holy_scrolls.txt`) were created with default system permissions (typically `0644`), making them readable by other users on the system.
**Learning:** In multi-user environments, sensitive logs should always be protected with restrictive permissions. Default process `umask` settings can lead to unintended data exposure.
**Prevention:** Explicitly set a restrictive `umask(0077)` at the start of the application or use restrictive mode bits (e.g., `0600`) when creating files and directories to ensure they are only accessible by the owner.
