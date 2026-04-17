# Sentinel Security Journal

## 2026-04-15 - Atomicity and TOCTOU in C
**Vulnerability:** The `init_system` function checked for directory existence with `stat` before calling `mkdir`, creating a Time-of-Check to Time-of-Use (TOCTOU) race condition.
**Learning:** Checking for file/directory existence before an operation is non-atomic and can be exploited.
**Prevention:** Perform the operation directly (`mkdir`) and handle the result (e.g., `EEXIST` via `errno`) to ensure atomicity.

## 2026-04-15 - Sensitive Data Persistence
**Vulnerability:** The `authenticate_user` function left the user's "prayer" (password) in the `command` buffer on the stack after use.
**Learning:** Sensitive data should be cleared from memory as soon as it is no longer needed to prevent exposure via memory dumps or other vulnerabilities.
**Prevention:** Use `memset` to zero out sensitive buffers before they go out of scope or the function returns.
