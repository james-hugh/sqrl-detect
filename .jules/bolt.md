## 2026-02-15 - [Efficient ASCII rendering and Log optimization]
**Learning:** In small C CLI applications, replacing loops of `printf` calls with a single `printf` using the `%.*s` precision specifier significantly reduces I/O overhead. Additionally, redundant system calls like `stat` in frequently called logging functions can be easily avoided with a static flag.
**Action:** Always look for nested `printf` loops in ASCII-heavy applications and consider using `%.*s` or building a buffer before printing.
