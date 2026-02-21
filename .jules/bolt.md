## 2024-05-15 - Optimized CLI rendering in STNM3K
**Learning:** In CLI applications with heavy ASCII-based visualizations, character-by-character `printf` calls in loops create significant overhead due to repeated format string parsing and system call invocation. Using `%.*s` with static template strings reduces these to a single `printf` call per line.
**Action:** Always prefer `%.*s` with static buffers for repeating character sequences in CLI rendering.
