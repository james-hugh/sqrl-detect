## 2026-04-15 - Optimizing ASCII Visualizations
**Learning:** Replacing nested loops of `printf` calls with formatted batch calls using precision specifiers (e.g., `%.*s`) yields measurable performance gains in CLI applications by reducing the number of system calls.
**Action:** Use precision specifiers and static character buffers for repeating patterns in CLI output.
