## 2026-03-25 - Reduced `printf` Overhead in CLI Visualizations
**Learning:** For terminal-based visualizations (like graphs or progress bars), character-by-character `printf` calls in nested loops can introduce significant system call overhead. Using the `%.*s` format specifier with static filler strings allows for bulk output in a single call, improving rendering performance and reducing the impact on the terminal emulator.
**Action:** Prioritize bulk `printf` with precision specifiers over character loops for repeated symbol rendering in CLI tools.
