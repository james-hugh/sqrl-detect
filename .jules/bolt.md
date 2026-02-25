## 2026-02-25 - CLI Rendering and String Handling Optimizations
**Learning:** Replacing character-by-character `printf` loops with `%.*s` precision specifiers and static template strings significantly reduces syscall overhead in CLI visualizations. Additionally, `ctime()` newline removal can be optimized from O(N) to O(1) by directly null-terminating at index 24, as `ctime()` returns a fixed-length string.
**Action:** Always prefer `%.*s` for repeating characters in CLI output and use fixed-index truncation for known fixed-length string outputs from standard library functions.
