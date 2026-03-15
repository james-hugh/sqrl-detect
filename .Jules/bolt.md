## 2026-03-12 - Syscall Optimization in CLI Rendering
**Learning:** Performing character-by-character `printf` calls in a loop (e.g., for rendering bars or graphs) introduces significant syscall overhead, which can bottleneck CLI performance.
**Action:** Use precision specifiers (`%.*s`) with static buffers to render repeated characters or substrings in a single `printf` call, drastically reducing the number of write operations to the terminal.
