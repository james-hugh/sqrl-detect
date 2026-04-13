## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-13 - Forgiving CLI Input Patterns
**Learning:** Implementing case-insensitive string matching and robust menu selection (supporting both numbers and keywords) reduces user frustration and makes CLI tools more accessible to a wider range of users.
**Action:** Use case-insensitive helpers for authentication and menu selection, and ensure menu loops are persistent until an explicit exit command is given.
