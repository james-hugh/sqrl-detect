# Bolt Performance Journal

## 2026-02-17 - Optimization of CLI and Time Handling
**Learning:** Minimizing printf calls and using static for read-only arrays reduces re-initialization overhead. Optimizing ctime() by direct null-termination at index 24 is more efficient than using strlen().
**Action:** Applied static to the threats array and implemented index-based ctime() cleanup.
