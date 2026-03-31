## 2026-03-29 - [Optimizing character-by-character printing]
**Learning:** Character-by-character `printf` calls in a tight loop create significant overhead compared to bulk output. Even for small CLI visualizations, using `%.*s` with static buffers can yield measurable performance gains (approx. 7% in this case).
**Action:** Always prefer bulk output techniques for repetitive CLI visualizations to reduce the number of system calls and loop overhead.
