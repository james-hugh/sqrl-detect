## 2026-03-12 - Syscall reduction in CLI rendering
**Learning:** In C CLI tools, character-by-character `printf` loops are a major syscall bottleneck. Using precision specifiers (`%.*s`) with static buffers allows rendering multiple characters in a single call, significantly reducing overhead.
**Action:** Always look for opportunities to batch character output in terminal-based visualizations.
