## 2026-04-27 - Secure Memory Clearing for Authentication
**Vulnerability:** Sensitive data (sacred prayer/password) lingering in memory after use, potentially exposed via memory dumps or buffer overreads.
**Learning:** Compilers may optimize away standard `memset` calls if the buffer is not used afterwards, leading to sensitive information remaining in RAM.
**Prevention:** Use a `secure_memzero` implementation with a `volatile` pointer to ensure memory is actually cleared regardless of compiler optimizations.
