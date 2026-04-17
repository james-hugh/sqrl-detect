## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-15 - Forgiving CLI Interactions
**Learning:** Implementing case-insensitive string matching and robust input validation (e.g., handling both numeric and textual commands) significantly reduces user cognitive load and prevents accidental session termination.
**Action:** Use portable helper functions like `str_contains_ignore_case` for flexible user input processing.
