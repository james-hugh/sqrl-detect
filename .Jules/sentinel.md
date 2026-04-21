# Sentinel's Security Journal

This journal documents critical security learnings and patterns discovered in the STNM3K codebase.

## 2026-04-20 - Hardened System Initialization and Data Protection
**Vulnerability:** Default file permissions were overly permissive (dependent on user umask), and sensitive authentication strings ("prayers") persisted in memory after use.
**Learning:** Using `umask(0077)` at the start of the application ensures that all subsequent file and directory creations (like the `logs` folder and `holy_scrolls.txt`) are restricted to the owner by default, regardless of the environment's umask. Additionally, sensitive buffers must be explicitly cleared using a `volatile` pointer to prevent compiler optimizations from skipping the zeroing operation (dead-store elimination). Clearing memory *immediately* after use (e.g., within an input loop) is safer than waiting until the end of the function.
**Prevention:** Always set a restrictive process-wide umask for security-sensitive applications and use a `secure_memzero` pattern for any buffer containing credentials or authentication tokens.
