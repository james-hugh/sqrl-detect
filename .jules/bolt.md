## 2026-02-17 - CLI Rendering and Array Optimization
**Learning:** Frequent small printf calls can be inefficient for CLI rendering. Marking local read-only arrays as static avoids repetitive stack allocation and initialization.
**Action:** Optimized `print_threat_meter` using `%.*s` precision specifiers to minimize printf calls and marked the `threats` array in `get_random_threat` as static.
