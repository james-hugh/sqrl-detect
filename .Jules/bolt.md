## 2026-02-23 - CLI Visualization Optimization
**Learning:** Replacing character-by-character loops with `%.*s` precision specifiers and static template strings in CLI visualizations reduces the number of `write` syscalls from O(N) to O(1) per line, significantly decreasing terminal rendering overhead.
**Action:** Use `%.*s` with static buffers for repeated character rendering in terminal UIs.
