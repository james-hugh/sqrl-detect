## 2026-04-15 - Redundant String Allocations in Static Data
**Learning:** Functions that frequently return string literals from a fixed set (e.g., threat messages) should declare the array as `static` to avoid redundant stack allocation and initialization on every call.
**Action:** Use `static` for fixed string lookup tables in frequently called functions.

## 2026-04-15 - Optimizing ASCII Visualizations
**Learning:** Replacing nested loops of `printf` calls with a single `printf` using precision specifiers (`%.*s`) and a static buffer of maximum expected width significantly reduces the number of system calls and improves terminal rendering performance.
**Action:** Use `%.*s` precision specifiers for repeated character output in terminal UI elements.
