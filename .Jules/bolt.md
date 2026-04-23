# Bolt Performance Journal

## 2026-04-22 - Reducing Printf Overhead
**Learning:** In STNM3K, `print_graph_of_chaos` uses a nested loop to print characters one by one. This causes significant overhead due to many small `printf` calls. Using static character buffers and the `%.*s` precision specifier can reduce the number of `printf` calls per bar to one.
**Action:** Replace nested loops with precision-limited string printing in visualization functions.
