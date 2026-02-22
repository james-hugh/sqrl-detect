## 2025-05-15 - CLI Rendering Bottlenecks
**Learning:** Character-by-character `printf` calls in CLI visualizations (like graphs or progress bars) create significant overhead due to repeated syscalls and terminal I/O. Using `%.*s` with static template strings can reduce `printf` calls from O(width) to O(1) per line.
**Action:** Always prefer `%.*s` with static buffers for rendering repeating ASCII characters in CLI tools.
