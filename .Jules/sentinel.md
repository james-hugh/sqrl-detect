## 2026-04-22 - Hardening System Initialization and Authentication
**Vulnerability:** Potential TOCTOU race condition in directory creation, overly permissive default file permissions, and sensitive authentication data lingering in memory.
**Learning:** Checking for directory existence before creation with `stat` and `mkdir` is non-atomic. Default process umask may allow other users to read sensitive logs. Standard `memset` can be optimized away by compilers if the buffer is not used again.
**Prevention:** Call `mkdir` directly and handle `EEXIST` via `errno`. Set `umask(0077)` at startup. Use a `secure_memzero` implementation with a `volatile` pointer to ensure memory is cleared.
