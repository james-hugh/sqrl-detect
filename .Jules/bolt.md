## 2026-03-18 - Optimized Visual Rendering via Static Buffers
**Learning:** Character-by-character `printf` loops in CLI visualization routines (like graph bars) generate excessive syscall overhead, slowing down the interface.
**Action:** Replace nested loops with static buffers and the `%.*s` format specifier to render strings of a specific length in a single `printf` call. This reduces overhead and improves terminal responsiveness.
