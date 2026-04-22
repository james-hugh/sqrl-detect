## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-22 - Case-Insensitive CLI Command Processing
**Learning:** For CLI tools, implementing case-insensitive string matching (e.g., via a portable `str_contains_ignore_case` helper) significantly improves user accessibility by reducing errors caused by minor capitalization differences in commands or authentication prompts.
**Action:** Use case-insensitive matching for all terminal-based user input commands to ensure a more forgiving and pleasant UX.
