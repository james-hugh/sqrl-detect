## 2026-03-19 - TOCTOU and Insecure Log Permissions
**Vulnerability:** The original `init_system` used a separate `stat` check followed by `mkdir`, which is susceptible to Time-of-Check to Time-of-Use (TOCTOU) race conditions. Additionally, default permissions were potentially too permissive.
**Learning:** Checking for file existence before creation is non-atomic and can be exploited. Setting `umask` at startup ensures all subsequent file/directory creations inherit safe default permissions.
**Prevention:** Use atomic operations like `mkdir` with `EEXIST` error handling and enforce restrictive `umask(0077)` to ensure sensitive data (like logs) is only accessible to the owner.
