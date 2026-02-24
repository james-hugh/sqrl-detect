## 2025-05-14 - Character-by-character CLI Rendering Overhead
**Learning:** Rendering CLI visualizations character-by-character using multiple `printf` calls is significantly slower than using precision specifiers (`%.*s`) with static template strings. This optimization reduces syscall frequency from O(N) to O(1) per line, which is especially impactful in high-latency terminal environments.
**Action:** Always prefer `%.*s` for repeating character patterns in CLI tools to minimize rendering overhead.
