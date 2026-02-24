## 2026-02-24 - Optimized CLI String Handling
**Learning:** Hard-coding the null-terminator at index 24 for `ctime()` results is a more efficient way to remove the trailing newline than using `strlen()`, as `ctime()` output is fixed-width. Using `static const` for frequently accessed read-only arrays prevents redundant stack allocation.
**Action:** Use fixed-index null termination for known-length strings and mark local read-only arrays as `static const`.
