## 2026-02-18 - Optimized CLI rendering and string handling in STNM3K

**Learning:** Significant performance gains (measured ~40% for the threat meter) can be achieved in CLI applications by reducing the number of `printf` calls. Using `%.*s` with static template strings allows for efficient rendering of repeated characters without the overhead of multiple function calls and buffer flushes. Additionally, in fixed-format strings like those returned by `ctime`, direct index access is faster than calling `strlen`.

**Action:** Always look for opportunities to batch `printf` calls in loops using precision specifiers and static filler strings. Prefer direct null-termination at known indices for fixed-format standard library string outputs.
