## 2026-04-15 - Optimizing ASCII Visualizations
**Learning:** Replacing nested loops of `printf` calls with static character buffers and the `%.*s` precision specifier significantly reduces syscall overhead in terminal applications.
**Action:** Use static buffers and precision specifiers for high-frequency or complex ASCII UI elements.
