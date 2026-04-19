
## 2026-04-19 - Optimized Terminal Graph Rendering
**Learning:** Replacing character-by-character loops with formatted string precision specifiers (\%.*s) and static buffers significantly reduces the number of printf calls and syscall overhead in C CLI applications.
**Action:** Use precision specifiers and static buffers for repeated terminal UI patterns like bar graphs or separators.
