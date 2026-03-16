
## 2026-03-12 - Optimized Graph Rendering
**Learning:** Character-by-character loops in C CLI tools can be a significant bottleneck due to repeated printf calls. Using precision specifiers (%.*s) with static buffers reduces overhead.
**Action:** Replace nested character-printing loops with single printf calls where possible.
