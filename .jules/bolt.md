## 2026-04-15 - Optimizing ASCII Rendering
**Learning:** Character-by-character `printf` loops in ASCII visualizations significantly increase syscall overhead and parsing time. Using static character buffers combined with the `%.*s` precision specifier reduces `printf` calls from O(N) to O(1) per line.
**Action:** Replace repeated single-character output calls with batch formatted calls using precision specifiers for all repeated patterns in terminal GUIs.
