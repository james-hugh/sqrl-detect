## 2026-04-08 - Optimized Graph Rendering
**Learning:** In terminal applications, multiple small `printf` calls (e.g., printing one character at a time in a loop) are significantly slower than a single formatted `printf` call due to buffering and system call overhead.
**Action:** Use the `%.*s` precision specifier with static buffers to render dynamic-length bars or graphs in a single call.
