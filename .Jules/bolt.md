## 2026-03-12 - Character-output routine optimization
**Learning:** In C CLI applications, replacing character-by-character `printf` loops with single `printf` calls using precision specifiers (`%.*s`) and static buffers significantly reduces syscall overhead and branching.
**Action:** Always look for loops printing repetitive patterns and replace them with formatted substring output from a static fill buffer.
