# Bolt's Journal

## 2026-05-05 - Initial Profiling
**Learning:** The `stnm3k.c` application is a small CLI tool with a `sleep(1)` bottleneck in its main loop. Many "optimizations" like replacing loops with string literals are negligible due to the I/O and sleep-bound nature of the app.
**Action:** Focus on reducing syscalls or optimizing string operations that occur in the hot path of logging or UI rendering, even if the absolute gain is small.

## 2026-05-05 - Printf Overhead in CLI loops
**Learning:** Replacing character-by-character loops with a single `printf` call using string precision specifiers (`%.*s`) significantly reduces the overhead of function calls and syscalls in a CLI application. While the application is `sleep(1)` bound, the CPU efficiency of the rendering logic improved by ~7.5% in isolation.
**Action:** Always look for ways to consolidate multiple `printf` or `write` calls into fewer operations when rendering ASCII graphics or large blocks of text.
