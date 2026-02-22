## 2026-02-22 - CLI Rendering Optimization
**Learning:** Using %.*s with static template strings reduces syscall overhead and simplifies character-by-character loops for visualizations like graphs.
**Action:** Optimized print_graph_of_chaos and used ctime null-termination at index 24 for faster logging.
