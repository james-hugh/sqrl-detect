## 2026-04-13 - Optimizing Graph Rendering
**Learning:** Replacing nested loops of `printf` calls with a single `printf` using the `%.*s` precision specifier and a static buffer can significantly reduce the number of system calls and improve terminal rendering performance.
**Action:** Use static character buffers and precision specifiers for repetitive ASCII art or bar graph rendering.
