## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-07 - CLI Case-Insensitivity and Persistence
**Learning:** For interactive CLI tools, case-insensitive matching for both authentication and menu selection significantly improves user accessibility by reducing errors from minor capitalization differences. Additionally, a persistent menu loop (rather than single-action execution) provides a smoother and more intuitive user experience.
**Action:** Use `strcasestr` (with `_GNU_SOURCE`) for case-insensitive CLI interactions and implement persistent menu loops for multi-action interfaces.
