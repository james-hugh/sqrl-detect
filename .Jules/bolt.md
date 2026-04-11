## 2026-04-08 - Optimized Row Rendering in terminal CLI
**Learning:** Replacing nested loops of `printf` calls with a single `printf` using `%.*s` and static buffers significantly reduces overhead in terminal-heavy applications.
**Action:** Always batch terminal output and use precision specifiers for repetitive character patterns.
