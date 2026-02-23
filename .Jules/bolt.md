## 2026-02-23 - Optimized ASCII Graph Rendering
**Learning:** Replacing character-by-character `printf` calls within a loop with `%.*s` precision specifiers and static template strings significantly reduces the number of system calls and terminal rendering overhead.
**Action:** Use `%.*s` for repeated character sequences in CLI visualizations to improve performance.
