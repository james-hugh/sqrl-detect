## 2026-02-19 - Optimization of CLI Visualizations
**Learning:** Replacing character-by-character loops with `%.*s` precision specifiers significantly reduces the number of `printf` calls and improves rendering efficiency for repetitive ASCII elements.
**Action:** Implemented `%.*s` in both the threat meter and the GUI graph of chaos to optimize terminal output performance.
