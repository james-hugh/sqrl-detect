## 2026-04-07 - Secure File and Directory Permissions via umask

**Vulnerability:** Default system umask (e.g., 0002 or 0022) results in new files and directories being world-readable or group-readable, potentially exposing sensitive application logs.

**Learning:** Relying on explicit `chmod` or `mkdir` permission arguments is not always sufficient if the underlying environment has a permissive `umask`. In this project, the `logs` directory and `holy_scrolls.txt` were being created with group/other read permissions, violating the Principle of Least Privilege.

**Prevention:** Explicitly set `umask(0077)` at application initialization to ensure all subsequent file and directory creations are restricted to the owner by default. Additionally, use idempotent directory creation patterns (`mkdir` with `EEXIST` check) to avoid race conditions or unnecessary `stat` calls.
