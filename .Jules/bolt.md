# Bolt Performance Journal
## 2026-03-12 - Syscall Optimization
**Learning:** Multiple small `printf` calls (like character-by-character loops) significantly increase system call overhead and slow down terminal applications.
**Action:** Use buffered output or larger formatting strings (like `%.*s`) to minimize the number of syscalls.

## 2026-03-12 - Static Buffer Safety
**Learning:** When using static buffers for visualization (e.g., `%.*s`), ensure the buffer is large enough to handle all possible output lengths to avoid visual bugs or partial rendering.
**Action:** Always dimension static visualization buffers to at least the maximum possible output width.
