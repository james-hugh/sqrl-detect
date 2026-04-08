## 2026-04-07 - Optimized printf in loop
**Learning:** In terminal applications, calling `printf` inside a nested loop for character-by-character output is significantly slower than using a single `printf` with a precision specifier (`%.*s`) and static buffers.
**Action:** Use static buffers and `%.*s` to batch character output in terminal UIs where performance is critical.
