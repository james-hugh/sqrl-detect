## 2026-04-14 - Batching printf calls in CLI graphs
**Learning:** In C terminal applications, replacing nested loops of `printf` calls with formatted batch calls (using static buffers and precision specifiers like `%.*s`) can measurably reduce I/O overhead and improve rendering performance for frequent UI updates.
**Action:** Use precision specifiers and pre-allocated character buffers for repeating patterns in CLI visualizations to minimize system calls.
