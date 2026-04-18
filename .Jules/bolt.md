## 2026-04-18 - Optimized ASCII Graph Rendering
**Learning:** Replacing iterative `printf` calls within a loop with formatted batch calls using precision specifiers (e.g., `%.*s`) reduces syscall overhead and slightly improves performance during high-frequency UI updates.
**Action:** Use precision specifiers for repeated character output in performance-sensitive terminal visualizations.
