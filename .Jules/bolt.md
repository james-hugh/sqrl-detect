## 2026-03-18 - Optimized CLI visualization output
**Learning:** Character-by-character `printf` loops in CLI tools are a major syscall bottleneck, especially when printing many characters per frame.
**Action:** Use `%.*s` with static buffers to batch character output into a single `printf` call. This significantly reduces the number of system calls and improves rendering performance for terminal animations and graphs.
