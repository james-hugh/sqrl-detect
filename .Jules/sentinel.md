## 2026-05-05 - Fix Authentication Bypass and Improve Memory Hygiene
**Vulnerability:** The authentication check used `strstr` to verify the sacred prayer, allowing any input containing "GLORY BE" (e.g., "NOT GLORY BE") to pass. Additionally, sensitive user input remained in memory after processing.
**Learning:** Using substring matching (`strstr`) for authentication is dangerous as it allows for bypasses with prefixed or suffixed strings. Furthermore, without explicit memory wiping, sensitive data can persist in the stack.
**Prevention:** Always use exact string comparison (`strcmp`) after trimming input for authentication. Implement and use a secure memory wiping function (with compiler barriers) to sanitize buffers containing sensitive information immediately after use.
