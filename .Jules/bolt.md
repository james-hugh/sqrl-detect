## 2026-04-11 - Optimized ASCII Graph Rendering
**Learning:** Replacing nested loops of `printf` calls with formatted batch calls using precision specifiers (`%.*s`) and static buffers significantly reduces the number of system calls and improves rendering performance for terminal-based graphs.
**Action:** Use static buffers and precision specifiers for variable-length ASCII bars or graphs instead of manual character-by-character loops.
