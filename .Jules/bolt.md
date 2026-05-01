# Bolt's Journal - Critical Performance Learnings

## 2026-04-29 - Reducing Syscall Overhead via Printf Batching
**Learning:** In terminal-based visualizations, calling `printf` for every character in a loop significantly increases overhead due to repeated syscalls. Using static buffers and the `%.*s` precision specifier allows batching the entire line into a single `printf` call.
**Action:** Always batch character-by-character output into strings or use precision specifiers for repeated patterns to minimize the number of `printf` calls.
