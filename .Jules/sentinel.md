## 2026-04-23 - Hardened System Initialization and Authentication
**Vulnerability:** Overly permissive log file permissions (0664) and sensitive authentication data persisting in memory after use.
**Learning:** Default umask and standard memory clearing (like just letting a buffer go out of scope) can leave sensitive data exposed to other users or memory forensic tools.
**Prevention:** Use `umask(0077)` for process-wide private file creation and implement `secure_memzero` with volatile pointers to ensure buffers containing secrets are reliably cleared.
