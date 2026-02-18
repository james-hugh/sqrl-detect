## 2026-02-18 - STNM3K Performance Overhaul
**Learning:** Minimizing `printf` calls and caching system checks significantly improves CLI responsiveness. Using `%.*s` with static template strings is much faster than character-by-character loops.
**Action:** Optimized `print_threat_meter` and `print_graph_of_chaos`. Cached `mkdir` in `init_system`.
