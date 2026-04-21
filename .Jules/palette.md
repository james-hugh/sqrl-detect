## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-20 - Forgiving Input in CLI Authentication
**Learning:** Strict case-sensitivity in CLI authentication prompts creates unnecessary friction and user error. Implementing a portable case-insensitive matching helper (e.g., using `tolower`) makes the interface more robust and user-friendly.
**Action:** Default to case-insensitive matching for user-entered commands and ritualistic inputs (like prayers or confirmations) unless security requirements strictly dictate otherwise.
