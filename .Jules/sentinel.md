## 2026-03-31 - [security improvement] Restrictive File Permissions
**Vulnerability:** Files created by the application (e.g., logs/holy_scrolls.txt) were being created with permissions that allow other users on the system to read them (e.g., 664, depending on the system's umask).
**Learning:** Default file creation permissions in C (like those in fopen or mkdir) are filtered by the process's umask. Relying on default behavior can lead to sensitive files being world-readable.
**Prevention:** Call `umask(0077)` at system initialization to ensure all subsequently created files and directories are only accessible by the owner (0600 for files, 0700 for directories).
