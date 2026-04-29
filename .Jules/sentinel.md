## 2026-04-27 - Secure Buffer Sanitization in C
**Vulnerability:** Sensitive authentication buffers (the "GLORY BE" prayer) were left on the stack after use, potentially exposing them in memory dumps or via subsequent stack-based attacks.
**Learning:** Standard memory clearing (like `memset`) can be optimized away by the compiler if the buffer is not subsequently read, leaving sensitive data in memory.
**Prevention:** Implement `secure_memzero` using a `volatile` pointer to force the compiler to perform the memory wipe, ensuring sensitive data is destroyed regardless of optimization levels.
