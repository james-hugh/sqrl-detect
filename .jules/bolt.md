## 2024-05-24 - Bulk String Output Optimization
**Learning:** In C CLI tools, repeated small calls to `printf` (like printing single characters in a loop) introduce significant overhead compared to single bulk `printf` calls with formatted strings. Using the `%.*s` precision specifier with pre-allocated static buffers effectively reduces this overhead while maintaining the same visual output.
**Action:** Always prefer bulk output for repeated visual elements (like progress bars or graphs) to minimize I/O system calls.
