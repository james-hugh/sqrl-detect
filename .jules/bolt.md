## 2025-05-14 - Baseline Performance Measurement
**Learning:** Baseline measurements established for core functions.
- log_event: 0.013457 s (1k iterations)
- print_threat_meter: 0.029902 s (100k iterations)
- print_graph_of_chaos: 0.106680 s (100k iterations)
- get_random_threat: 0.020463 s (1M iterations)
**Action:** Use these to verify optimization impact.
## 2025-05-14 - Optimization Impact
**Learning:** CLI rendering and logging optimizations yielded significant improvements.
- log_event: 0.011683 s (13% faster)
- print_threat_meter: 0.017932 s (40% faster)
- print_graph_of_chaos: 0.082868 s (22% faster)
**Action:** Always prefer %.*s over character-by-character loops for terminal UI rendering.
