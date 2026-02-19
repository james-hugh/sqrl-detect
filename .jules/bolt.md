## 2026-02-19 - CLI Visualization Optimization
**Learning:** Replacing character-by-character printf loops with %.*s precision specifiers and static template strings significantly reduces terminal rendering overhead. Optimizing ctime() newline removal by direct index null-termination (timestamp[24] = '\0') is more efficient than calling strlen().
**Action:** Refactored print_threat_meter and print_graph_of_chaos to use %.*s and static templates. Updated log_event to optimize timestamp formatting.
