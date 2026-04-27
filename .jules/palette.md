## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-25 - Secure Memory Sanitization in C
**Learning:** To protect sensitive in-memory data in C, use a `secure_memzero` implementation that utilizes a `volatile` pointer to ensure the compiler does not optimize away the operation (dead-store elimination), especially for buffers not used again before returning.
**Action:** Always call `secure_memzero` on sensitive buffers like passwords or sacred prayers before they go out of scope.
