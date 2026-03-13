## 2026-03-12 - Hardening Default File Permissions and Directory Creation
**Vulnerability:** Insecure default file permissions (0664) for sensitive logs and TOCTOU race condition in directory creation.
**Learning:** System umask can lead to overly permissive files (e.g., world-readable logs). Using `stat` before `mkdir` creates a race condition window.
**Prevention:** Call `umask(0077)` early in `init_system` to ensure all files/directories are private by default. Use atomic `mkdir` and check `errno == EEXIST` to prevent TOCTOU issues.
