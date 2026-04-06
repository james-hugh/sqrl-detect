# Bolt's Performance Journal

## 2026-04-04 - Initializing Journal
**Learning:** Found that `stnm3k.c` has inconsistent optimization patterns. `print_threat_meter` uses efficient `%.*s` formatting, while `print_graph_of_chaos` uses an inefficient nested loop with multiple `printf` calls.
**Action:** Will implement the same `%.*s` optimization in `print_graph_of_chaos` to reduce the number of `printf` calls per invocation from ~62 to 7.
