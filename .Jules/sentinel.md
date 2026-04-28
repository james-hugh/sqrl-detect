## 2026-04-28 - Secure Buffer Erasure for Sensitive Inputs
**Vulnerability:** Standard memory clearing (e.g., memset) can be optimized away by the compiler if the buffer is not used afterward, leaving sensitive data (passwords) in memory.
**Learning:** Compilers perform dead-store elimination which can undermine security practices.
**Prevention:** Use a secure_memzero implementation with a volatile pointer to ensure the wipe operation is always executed.
