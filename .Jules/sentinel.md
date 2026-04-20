## 2026-04-19 - Atomic Directory Creation and Restrictive Permissions
**Vulnerability:** Non-atomic directory checks (e.g., `stat` followed by `mkdir`) can lead to TOCTOU race conditions, and default `umask` settings may create log files with overly permissive access.
**Learning:** Calling `mkdir` directly and handling `EEXIST` via `errno` ensures atomicity, while `umask(0077)` guarantees that all subsequent file and directory creations are restricted to the owner by default.
**Prevention:** Always use atomic system calls and set an explicit, restrictive `umask` before creating sensitive directories or files.
