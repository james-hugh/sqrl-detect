## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-13 - Forgiving CLI Input Pattern
**Learning:** Forcing users to match exact casing in CLI commands or authentication prompts creates unnecessary friction. Implementing a portable case-insensitive matching utility improves accessibility and reduces user error.
**Action:** Use `str_contains_ignore_case` (or similar) for all user-facing string comparisons in CLI tools to provide a more "forgiving" interaction model.
