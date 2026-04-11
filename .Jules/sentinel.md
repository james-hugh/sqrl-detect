## 2026-04-08 - Secure File and Directory Creation
**Vulnerability:** Insecure default file permissions (world-readable logs) and TOCTOU race conditions during directory initialization.
**Learning:** Default process `umask` (often 0022 or 0002) can lead to sensitive log files being world-readable. Additionally, checking for a directory's existence before creating it (`stat` then `mkdir`) introduces a TOCTOU (Time-of-Check to Time-of-Use) window.
**Prevention:** Use `umask(0077)` early in the process to ensure all subsequent file/directory creations are restricted by default. Use atomic, idempotent operations like calling `mkdir` directly and handling `EEXIST` to avoid race conditions.
