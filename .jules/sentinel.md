## 2026-04-15 - TOCTOU and Insecure Directory Creation
**Vulnerability:** Race condition in directory creation and insecure default permissions (0700 was used but not guaranteed without `umask`).
**Learning:** Checking for directory existence before creation is vulnerable to TOCTOU. Calling `mkdir` directly and handling `EEXIST` via `errno` is more robust.
**Prevention:** Use `umask(0077)` to ensure private-by-default file creation and handle `mkdir` idempotently via `errno`.
