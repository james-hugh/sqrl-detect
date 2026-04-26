## 2026-04-25 - C Output and Stack Optimization
**Learning:** In terminal-heavy applications, replacing loops of `printf` with `%.*s` and static buffers significantly reduces syscall overhead. Additionally, `static const char* const` for string arrays prevents unnecessary stack allocations on every function call.
**Action:** Always prefer batching terminal output and using static storage for immutable lookup data in performance-critical paths.
