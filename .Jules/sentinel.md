## 2026-04-15 - Atomic Directory Creation and Permissions
**Learning:** Using `umask(0077)` combined with calling `mkdir` directly (and checking `errno` for `EEXIST`) ensures that sensitive directories are created with secure permissions and avoids TOCTOU race conditions.
**Action:** Always prefer atomic `mkdir` with restrictive `umask` over pre-creation `stat` checks.

## 2026-04-15 - Secure Memory Sanitization
**Learning:** Sensitive authentication data in memory should be zeroed out using `memset` immediately after use to prevent accidental exposure via memory dumps or buffer reuse.
**Action:** Use `memset(buffer, 0, sizeof(buffer))` for all sensitive user input after processing.
