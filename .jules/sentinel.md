## 2026-04-12 - Insecure Default Permissions and TOCTOU in Log Initialization
**Vulnerability:** The application created its log directory and files with overly permissive default permissions (allowing group/others to read/write) and used a "check-then-act" pattern (`stat` followed by `mkdir`) which is susceptible to TOCTOU (Time-of-Check to Time-of-Use) race conditions.
**Learning:** Default system `umask` can lead to insecure file permissions if not explicitly managed. Additionally, checking for a directory's existence before creating it is inherently racy in multi-user environments.
**Prevention:** Use `umask()` to set a restrictive baseline for the process and attempt atomic operations (like `mkdir` directly and checking for `EEXIST`) instead of pre-checking with `stat`.
