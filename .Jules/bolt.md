## 2026-04-27 - Optimizing terminal output performance in C
**Learning:** In C terminal applications, repeated `printf` calls in a nested loop (e.g., printing characters one by one for a graph) significantly increase overhead due to syscalls and format string parsing. Using static character buffers combined with the `%.*s` precision specifier allows printing an entire row in a single `printf` call, yielding measurable performance gains.
**Action:** Always prefer batching character output using `%.*s` and static buffers over character-by-character loops when rendering CLI visualizations.
