## 2026-02-22 - Optimized CLI Rendering and Timestamping
**Learning:** Minimizing `printf` calls and using `%.*s` precision specifiers for repeated characters significantly reduces terminal rendering overhead. Additionally, null-terminating the `ctime()` result at index 24 is more efficient than using `strlen()` since the output format is fixed.
**Action:** Use precision specifiers for static string templates and direct index manipulation for fixed-length library outputs.
