## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-15 - Case-Insensitivity in CLI Authentication
**Learning:** Rigid, case-sensitive input requirements in CLI authentication (like requiring "GLORY BE" in all caps) create unnecessary friction and accessibility barriers for users. Implementing a portable case-insensitive matching helper improves the "forgivingness" of the interface.
**Action:** Use case-insensitive string matching for user-entered commands and authentication strings to improve accessibility and user experience.
