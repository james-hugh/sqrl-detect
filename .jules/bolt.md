## 2026-02-21 - Optimization of CLI Visualization and Logging
**Learning:** Replacing `strlen()` with fixed-index null-termination for standard fixed-length strings like `ctime()` (26 chars including newline) saves redundant traversals. Using `static const` for read-only local arrays prevents repeated allocation/initialization on the stack during frequent function calls.
**Action:** Always prefer static const for local read-only data and leverage fixed-length string properties for termination when applicable.
