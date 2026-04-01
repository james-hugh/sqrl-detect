## 2026-03-31 - Initial Performance Review
**Learning:** The `print_graph_of_chaos` function uses character-by-character `printf` calls in a nested loop, which increases system call overhead.
**Action:** Use bulk output techniques (like precision specifiers with static buffers) to reduce the number of `printf` calls.
