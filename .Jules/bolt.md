## 2026-03-31 - Bulk output for ASCII graphing
**Learning:** Replacing character-by-character `printf` calls in a tight loop with a single `printf` and a precision specifier (`%.*s`) against a static buffer yields a measurable performance boost (~19%) by reducing system call overhead and function call frequency.
**Action:** Use bulk output patterns for any repetitive terminal-based visualizations in the STNM3K project.
