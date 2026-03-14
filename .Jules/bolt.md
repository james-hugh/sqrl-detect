## 2026-03-12 - [Optimized Character-by-Character Printing]
**Learning:** In C CLI tools, loops that call `printf` for individual characters are a significant performance bottleneck due to function call overhead and potential syscalls.
**Action:** Replace nested character-printing loops with single `printf` calls using precision specifiers (`%.*s`) and static buffers to significantly reduce overhead.
