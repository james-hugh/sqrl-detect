## 2026-04-13 - Restricted Log Permissions
**Vulnerability:** Default file creation permissions often allow other users on the system to read sensitive logs, potentially leaking system state or user activity.
**Learning:** Using `umask(0077)` at the start of the application ensures that all files and directories created by the process (like the `logs/` directory and `holy_scrolls.txt`) are only accessible by the owner.
**Prevention:** Explicitly set a restrictive `umask` or use fine-grained permission flags during `mkdir` and `open` calls for any security-sensitive data.
