# Bolt's Performance Journal ⚡

This journal records critical performance-related learnings for STNM3K.

## 2026-03-19 - Initial Assessment
**Learning:** Found that `print_graph_of_chaos` uses nested loops and multiple `printf` calls per line, which increases syscall overhead.
**Action:** Plan to replace nested loops with `%.*s` and static buffers, similar to how `print_threat_meter` is implemented.
