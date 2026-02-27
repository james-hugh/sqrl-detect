## 2025-05-15 - CLI Visualization Optimization
**Learning:** In character-heavy CLI displays, character-at-a-time `printf` loops in C can be a significant bottleneck due to formatting engine overhead. Replacing these with `%.*s` and static template strings reduces the overhead from O(N) to O(1) per line.
**Action:** Use `%.*s` and static template strings for ASCII bars or repeated characters in the CLI visualization engine to improve rendering performance.
