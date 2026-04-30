## 2026-04-29 - Secure Memory Handling for Authentication
**Vulnerability:** Sensitive authentication data (sacred prayer) lingering in memory after authentication check.
**Learning:** Standard memory clearing can be optimized away by compilers if the buffer is not used afterwards. Using a volatile pointer in a custom `secure_memzero` function ensures the wipe happens.
**Prevention:** Always wipe sensitive buffers at all exit points of authentication functions using a compiler-resistant method like volatile-pointer clearing.
