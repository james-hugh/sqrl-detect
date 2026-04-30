## 2026-04-29 - Secure Memory Wiping
**Vulnerability:** Sensitive authentication buffers can remain in memory after use, potentially being exposed in core dumps or through other memory-reading vulnerabilities.
**Learning:** Standard `memset` or simple loops can be optimized away by the compiler if it determines the buffer is no longer used, leaving sensitive data in RAM.
**Prevention:** Use a `volatile` pointer in a custom `secure_memzero` function to ensure the compiler does not optimize away the memory wipe.
