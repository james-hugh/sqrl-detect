## 2026-05-04 - Defense in Depth: Secure Memory Wiping
**Vulnerability:** Sensitive user input (e.g., authentication prayers) persisting in the stack after function return.
**Learning:** Compilers may optimize away standard memset calls if the buffer is not used afterwards, leaving sensitive data in memory.
**Prevention:** Use a secure_memzero implementation with a compiler barrier (__asm__ __volatile__) to ensure memory is wiped.
