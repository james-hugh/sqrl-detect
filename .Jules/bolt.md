# Bolt's Journal - Critical Learnings Only

## 2026-03-22 - Optimizing I/O-bound ASCII Graph Rendering
**Learning:** In C, repeated character-by-character `printf` calls in a tight loop create significant overhead due to format string parsing and multiple syscalls. Replacing the loop with a single `fwrite` using a pre-defined `static const char[]` buffer provides a measurable (~50%) performance boost in simulated high-frequency rendering scenarios.
**Action:** Always check for character-by-character output loops in visualization code and replace them with block writes using static templates where the output length is bounded and predictable.
