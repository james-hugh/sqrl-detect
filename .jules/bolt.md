## 2026-02-25 - CLI Rendering and String Optimization
**Learning:** Using `%.*s` precision specifiers with static template strings reduces the number of `printf` syscalls and avoids manual loops for repeated characters, improving rendering performance in character-heavy CLI displays.
**Action:** Replace character-by-character loops with `%.*s` and mark local read-only arrays as `static const` to avoid redundant re-initialization.
