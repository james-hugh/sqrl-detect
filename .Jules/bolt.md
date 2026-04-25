# Bolt's Journal - Critical Learnings

⚡ Speed is a feature. Every millisecond counts.

## 2026-04-25 - Batching Terminal Output
**Learning:** In C terminal applications, character-by-character `printf` calls in loops can be significantly slower than batching output into a single `printf` call using static buffers and the `%.*s` precision specifier. In STNM3K, this optimization reduced rendering time for the chaos graph by ~18-20%.
**Action:** Always look for opportunities to batch formatted output in high-frequency visualization loops.
