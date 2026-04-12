## 2026-04-12 - Optimizing ASCII Graphs with Precision Specifiers
**Learning:** In terminal applications, replacing nested loops and multiple `printf` calls with formatted batch calls using precision specifiers (`%.*s`) and static buffers can significantly reduce I/O overhead and improve rendering speed.
**Action:** Use `%.*s` and pre-defined character buffers for drawing repetitive ASCII UI elements.
