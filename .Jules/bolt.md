# Bolt's Journal - Performance Learnings

## 2026-03-25 - Caching Formatted Timestamps in C Logging
**Learning:** Calling `ctime()` in a high-frequency logging function can be expensive due to its internal time decomposition and string formatting logic. Since `time(NULL)` only changes once per second, caching the result of `ctime()` and only recalculating it when the second actually increments can yield a significant performance boost in micro-benchmarks (up to 98% reduction in overhead).
**Action:** For performance-sensitive logging code, use `static` variables to cache the formatted timestamp and update it only when `time(NULL)` returns a new value.
