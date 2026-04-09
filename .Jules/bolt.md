## 2026-04-08 - Optimized Console Graph Rendering
**Learning:** Rendering ASCII graphs by calling `printf` for each individual character in a loop is highly inefficient due to the overhead of format string parsing and buffered I/O synchronization. Using `%.*s` with static buffers allows rendering the same line in a single call.
**Action:** Use static buffers and precision specifiers for repetitive console output patterns to minimize I/O syscalls and library overhead.
