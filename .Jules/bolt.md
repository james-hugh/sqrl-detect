## 2026-04-27 - Optimizing UI Rendering in C CLI

**Learning:** Reducing the number of `printf` calls by batching output significantly improves performance in terminal applications. Using `static` character buffers combined with the `%.*s` precision specifier allows for dynamic-length string printing without repeated loops or memory allocations, avoiding syscall overhead.

**Action:** When rendering repetitive UI elements (like progress bars or graphs), use pre-allocated buffers and single `printf` calls instead of character-by-character loops.
