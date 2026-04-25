## 2026-04-25 - TOCTOU and Sensitive Data Persistent in Memory
**Vulnerability:** The application was vulnerable to a TOCTOU (Time-of-Check to Time-of-Use) race condition in directory creation and left sensitive authentication data in memory buffers after use.
**Learning:** Checking for directory existence with `stat()` before calling `mkdir()` is non-atomic and prone to race conditions. Additionally, standard compiler optimizations can skip `memset()` calls on buffers that are not accessed again before they go out of scope.
**Prevention:** Use atomic system calls like `mkdir()` directly and check `errno` for `EEXIST`. Implement a `secure_memzero` function using a `volatile` pointer to ensure sensitive data is cleared from memory regardless of compiler optimizations.
