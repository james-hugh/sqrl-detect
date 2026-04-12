# Bolt's Performance Journal

## 2026-04-12 - Identifying Rendering Bottleneck in STNM3K
**Learning:** The `print_graph_of_chaos` function uses nested loops with individual `printf` calls for each character. In terminal applications, reducing the number of syscalls/library calls to `printf` by batching output or using precision specifiers can significantly improve performance when called frequently.
**Action:** Replace the inner loop in `print_graph_of_chaos` with a single `printf` using `%.*s` and static buffers.
