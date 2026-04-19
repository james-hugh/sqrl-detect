## 2026-04-19 - Atomic Directory Creation and umask
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition in directory creation and insecure default permissions.
**Learning:** Checking for directory existence with `stat` before calling `mkdir` is non-atomic and can be exploited.
**Prevention:** Call `mkdir` directly and handle `EEXIST` via `errno`, and use `umask` to enforce restricted permissions at the process level.
