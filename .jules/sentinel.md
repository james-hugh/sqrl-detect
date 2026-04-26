## 2026-04-25 - TOCTOU and Secure Memory Clearing
**Vulnerability:** TOCTOU race condition in directory creation and sensitive data lingering in stack memory.
**Learning:** Checking for directory existence with `stat` before calling `mkdir` creates a race condition. In C, stack buffers containing sensitive user input (like passwords or prayers) should be explicitly cleared before the function returns to prevent exposure through memory dumps or exploits.
**Prevention:** Use `mkdir` directly and check `errno == EEXIST`. Implement `secure_memzero` with a `volatile` pointer to ensure the compiler does not optimize away the clearing of sensitive buffers.
