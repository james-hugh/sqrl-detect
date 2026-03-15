# 🛡️ Sentinel Journal

## 2026-03-12 - TOCTOU and Insecure Default Permissions
**Vulnerability:** The `init_system` function used a `stat`/`mkdir` sequence, which is susceptible to a Time-of-Check to Time-of-Use (TOCTOU) race condition where an attacker could replace the target path between the check and the creation. Additionally, the application relied on the environment's default `umask`, leading to overly permissive log files.
**Learning:** C applications that create directories or files must use atomic operations and explicitly set a restrictive `umask` to ensure defense in depth, especially for sensitive data like "Holy Scrolls" (security logs).
**Prevention:** Implement `umask(0077)` at the start of the application to ensure all created files/dirs are restricted to the owner by default. Use atomic `mkdir` calls and check `errno != EEXIST` instead of pre-checking with `stat`.
