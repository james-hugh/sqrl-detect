## 2026-03-19 - Syscall Reduction in Character-Output Routines
**Learning:** In CLI tools with high-frequency UI updates, character-by-character `printf` loops are a major syscall bottleneck. Using `%.*s` with static buffers allows the OS to batch I/O more effectively.
**Action:** Replace nested character-output loops with precision-field string formatting where possible to improve rendering performance.
