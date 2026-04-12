## 2026-04-12 - Case-Insensitive CLI and Robust Menu Selection
**Learning:** Using `strcasestr` significantly improves CLI accessibility by reducing capitalization errors, but numeric menu selection requires explicit boundary checks (e.g., `command[1] == '\n'`) to prevent multi-digit inputs from accidentally triggering single-digit options.
**Action:** Always pair string-based command matching with explicit boundary or length checks for numeric shortcuts.
