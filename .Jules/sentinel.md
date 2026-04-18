# Sentinel Security Journal

## 2026-04-18 - Secure Initialization and Memory Handling
**Vulnerability:** TOCTOU race condition in directory creation, overly permissive log file permissions (inherited from default umask), and sensitive authentication strings lingering in memory.
**Learning:** Even simple simulated tools can inherit insecure defaults from the environment (like umask). Checking for directory existence before creation is a classic race condition; it's better to attempt the operation and handle the error.
**Prevention:** Use `umask(0077)` for applications handling sensitive logs to enforce owner-only access. Always zero out buffers containing secrets or authentication data immediately after use. Use atomic directory creation.
