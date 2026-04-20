## 2026-04-19 - Reducing Syscall Overhead in Terminal Rendering
**Learning:** Replacing nested loops of `printf` calls with static character buffers and the `%.*s` precision specifier significantly reduces the number of system calls and internal buffer flushing, leading to a measurable performance improvement in high-frequency CLI updates.
**Action:** Use batch formatting with precision specifiers for repetitive ASCII visualizations instead of per-character output loops.
