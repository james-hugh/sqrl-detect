## 2026-04-15 - Robust Directory Creation
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition in directory creation using `stat` then `mkdir`.
**Learning:** Checking for directory existence before creating it allows a race window.
**Prevention:** Call `mkdir` directly and handle the `EEXIST` error via `errno` to ensure atomicity. Use `umask` to enforce strict default permissions on sensitive directories.
