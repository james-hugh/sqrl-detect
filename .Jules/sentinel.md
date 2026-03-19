## 2026-03-19 - TOCTOU and Insecure Default File Permissions
**Vulnerability:** A Time-of-Check-to-Time-of-Use (TOCTOU) race condition in `init_system` when checking for the log directory's existence using `stat` before calling `mkdir`. Additionally, the program relied on the system's default `umask`, potentially creating log files with overly permissive access.

**Learning:** Using `stat` followed by `mkdir` is not atomic; an attacker could create a symbolic link at the target path between the check and the directory creation. Furthermore, logs containing sensitive monitoring data should always be restricted to the owner to prevent information leakage.

**Prevention:** Use atomic directory creation with `mkdir` and handle the `EEXIST` error to avoid race conditions. Set a restrictive `umask(0077)` at the start of the program to ensure all subsequent file and directory creations default to owner-only permissions.
