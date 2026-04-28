## 2026-04-28 - Optimized Terminal Output via Buffer Batching
**Learning:** Repeatedly calling printf for single characters (e.g., in loops) significantly increases syscall overhead. Using static character buffers combined with the %.*s precision specifier allows batching output into a single call.
**Action:** Use static buffers and string precision for repeated character patterns in CLI visualizations.
