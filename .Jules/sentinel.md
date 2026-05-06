## 2026-05-05 - [Authentication Bypass and Memory Hygiene]
**Vulnerability:** Use of strstr for authentication matching allowed partial matches (e.g., "NOT GLORY BE") to pass. Sensitive user input remained in memory after processing.
**Learning:** strstr is dangerous for exact matching; strcmp with proper newline trimming is required. Compilers may optimize away simple memset calls, necessitating a memory barrier.
**Prevention:** Always use strcmp for secrets. Implement secure_memzero with compiler barriers and use 'goto cleanup' to ensure it runs on all exit paths.
