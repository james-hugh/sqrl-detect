## 2026-04-19 - Reducing syscall overhead in ASCII rendering
**Learning:** Replacing nested loops of `printf` calls for individual characters with a single formatted `printf` using precision specifiers (`%.*s`) and static buffers significantly reduces system call overhead.
**Action:** Always look for opportunities to batch terminal output in performance-critical loops, especially in CLI applications with real-time or high-frequency updates.
