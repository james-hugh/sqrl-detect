## 2026-02-18 - Optimized CLI Visualizations and Time Formatting

**Learning:** Performance in CLI applications can be significantly improved by minimizing `printf` calls. Using precision specifiers like `%.*s` with static template strings for repeating characters (e.g., progress bars) is much faster than character-by-character loops. Additionally, `ctime()` returns a string with a trailing newline; null-terminating at index 24 is more efficient than calling `strlen` and then subtracting 1.

**Action:** Refactored `print_threat_meter` to use `%.*s` and optimized `log_event` to use index-based `ctime` trimming.
