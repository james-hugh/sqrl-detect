## 2026-02-20 - CLI Visualization Optimization
**Learning:** Character-by-character printf loops in CLI rendering (e.g., in STNM3K) are significantly less efficient than using %.*s precision specifiers with static template strings. In this codebase, transitioning to buffered printf reduced rendering overhead by approximately 20%.
**Action:** Always prefer %.*s and static template strings for repeated character sequences in CLI visualizations to minimize library call overhead and system call frequency.
