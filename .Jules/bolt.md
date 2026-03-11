## 2026-02-19 - Identifying Bottlenecks in STNM3K
**Learning:** In simple CLI applications like STNM3K, frequent calls to `printf` in nested loops can be a source of inefficiency. Buffering output or using fewer, more powerful `printf` calls (like `%.*s`) is significantly faster than calling `printf` for individual characters.
**Action:** Replace nested loops that call `printf` character-by-character with single `printf` calls using precision and static buffers.
