## 2026-03-20 - Character-by-Character Printf Bottleneck
**Learning:** In CLI tools that render graphs or UI elements, repeated `printf` calls for individual characters (especially inside loops) create significant syscall overhead. Using `%.*s` with static pre-filled buffers allows printing entire sequences of characters in a single operation, which is measurably faster even in optimized C code.

**Action:** Prefer `%.*s` with static buffers over nested loops for repetitive character output to improve rendering performance and reduce syscall pressure.
