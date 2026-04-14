
## 2026-04-13 - Optimized Redundant Output and Allocations in STNM3K
**Learning:** In terminal applications, repeated `printf` calls in nested loops for drawing UI elements (like progress bars or graphs) are significantly slower than a single formatted `printf` using the `%.*s` precision specifier with a static buffer. Additionally, moving small read-only arrays to `static` storage avoids unnecessary stack re-allocation.
**Action:** Always prefer batching character output using `%.*s` and static buffers for repetitive UI rendering.
