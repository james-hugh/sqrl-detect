## 2026-04-15 - Optimizing repetitive character output in C
**Learning:** Using a loop of `printf` calls for individual characters is significantly slower than using a single `printf` with a precision specifier (`%.*s`) and a static buffer. The latter reduces function call overhead and allows the standard library to optimize the output.
**Action:** When printing repeated characters up to a known maximum length, use `static const` buffers and precision specifiers instead of character-by-character loops.
