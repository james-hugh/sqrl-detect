## 2026-03-20 - Defense-in-Depth for File Logs
**Vulnerability:** Default file and directory permissions (e.g., 0755 or 0644) could allow other users on the system to read sensitive security logs ("Holy Scrolls").
**Learning:** Initializing the environment with `umask(0077)` ensures that all subsequently created files and directories are restricted to the owner by default, providing a baseline of "secure by default" behavior.
**Prevention:** Always set a restrictive `umask` at the entry point of security-sensitive applications and use explicit permissions (e.g., 0700) when creating directories.

## 2026-03-20 - TOCTOU Race Condition in Directory Creation
**Vulnerability:** Using `stat()` followed by `mkdir()` creates a Time-of-Check to Time-of-Use (TOCTOU) window where an attacker could potentially replace the path with a symbolic link.
**Learning:** Direct calls to `mkdir()` are safer when checked against `errno == EEXIST`. This makes the operation more atomic and robust against pre-existing files or race conditions.
**Prevention:** Prefer direct system calls with error code checking over "check-then-act" patterns for filesystem operations.
