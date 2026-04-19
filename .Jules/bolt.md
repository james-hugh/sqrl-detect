## 2026-04-19 - Optimized Terminal Graphics with Precision Specifiers
**Learning:** Replacing character-by-character printing loops with `printf("%.*s", ...)` using static buffers significantly reduces the number of system calls and improves terminal rendering performance.
**Action:** Use static buffers and precision specifiers for repeated character output in CLI applications.
