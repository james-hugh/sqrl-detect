## 2026-04-08 - Reducing Printf Calls for ASCII Rendering
**Learning:** In high-frequency terminal updates, reducing the number of printf calls by using static buffers and precision specifiers (e.g., %.*s) can improve performance and reduce flicker.
**Action:** Batch character-by-character prints into single printf calls when possible.
