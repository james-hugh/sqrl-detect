## 2026-04-29 - Secure Memory Wiping with Volatile Pointers
**Vulnerability:** Sensitive authentication data (the "sacred prayer") and user commands were left in stack-allocated buffers after use, potentially allowing them to be recovered from memory.
**Learning:** Standard `memset` or zeroing loops can be optimized away by modern compilers if the buffer is not accessed again before it goes out of scope, leaving sensitive data exposed.
**Prevention:** Use a `secure_memzero` utility that employs a `volatile` pointer to force the compiler to perform the memory write operations, ensuring sensitive data is actually cleared before the buffer is discarded.
