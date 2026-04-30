## 2026-04-29 - Printf Batching for Graph Rendering
**Learning:** Repeatedly calling printf for single characters in a loop is significantly slower than using the `%.*s` precision specifier with a static buffer to print the entire sequence at once.
**Action:** Use static character buffers and precision specifiers to batch terminal output for repeated characters.
