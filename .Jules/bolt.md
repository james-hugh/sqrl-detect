# Bolt's Journal - STNM3K Performance

## 2026-04-29 - Initializing Journal
**Learning:** Performance optimizations in C terminal applications often involve reducing the frequency of expensive syscalls (like `write` via `printf`). Replacing character-by-character loops with batched output using `%.*s` and static buffers can provide significant measurable improvements.
**Action:** Always look for opportunities to batch terminal output and use static buffers for repeated string patterns.
