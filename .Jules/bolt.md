## 2026-04-15 - Optimizing ASCII Rendering
**Learning:** Replacing character-by-character `printf` calls in a loop with a single `printf` using `%.*s` and static buffers significantly reduces system call overhead.
**Action:** Always prefer batching output or using precision specifiers for repetitive character patterns in CLI tools.
