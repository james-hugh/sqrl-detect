## 2026-03-18 - Hardened Directory Creation and Restrictive Permissions
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition during log directory creation and insecure default file permissions.
**Learning:** Using `stat()` followed by `mkdir()` creates a window where an attacker can replace the directory with a symbolic link. Additionally, relying on default `umask` can result in overly permissive log files.
**Prevention:** Use an atomic `mkdir()` call and check for `EEXIST` via `errno`. Set a restrictive `umask(0077)` at the start of the application to ensure all created files/directories are accessible only by the owner.
