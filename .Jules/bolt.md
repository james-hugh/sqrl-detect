## 2026-03-12 - Syscall Optimization in Character Loops
**Learning:** Character-by-character output (e.g., in a loop) in C CLI tools can be a significant performance bottleneck due to excessive syscalls (`write`).
**Action:** Use static buffers and string formatting (like `%.*s`) to print multiple characters at once, reducing the number of syscalls and improving the overall efficiency of terminal-based visualizations.
