## 2026-04-19 - Hardening STNM3K Initialization and Auth
**Vulnerability:** Weak file permissions (0664 for logs), TOCTOU in directory creation, and potential sensitive data persistence in memory.
**Learning:** Default umask can lead to overly permissive logs. Using `stat` before `mkdir` creates a race condition window.
**Prevention:** Use `umask(0077)` for process-wide restriction and atomic `mkdir` with `EEXIST` check. Explicitly `memset` sensitive buffers.
