## 2026-04-15 - Batch Terminal Output for Performance
**Learning:** Replacing nested loops of `printf` calls with formatted batch calls using precision specifiers (e.g., `%.*s`) and static buffers significantly reduces the number of system calls, leading to measurable performance gains in CLI applications.
**Action:** Use static character buffers and `%.*s` for repeated character sequences in terminal visualizations.
