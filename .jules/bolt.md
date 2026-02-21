## 2026-02-21 - Optimizing CLI Performance and Resource Management
**Learning:** Static local arrays in C avoid redundant re-initialization on every function call, and optimizing common string operations like `ctime()` newline removal using direct index access (null-terminating at index 24) significantly reduces overhead in logging-intensive CLI applications.
**Action:** Use `static const` for read-only local arrays and prefer direct buffer manipulation over `strlen` for fixed-format strings.
