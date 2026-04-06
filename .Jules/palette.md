## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-06 - Case-Insensitive Interaction and Integrated Log Viewing
**Learning:** For CLI tools, particularly those with a playful or repetitive theme, case-insensitive input handling significantly lowers the friction of interaction and prevents unnecessary "incorrect input" errors. Providing an in-app log viewer also enhances the UX by keeping the user within the main application flow instead of forcing them to manually open external files.
**Action:** Implement case-insensitive string matching (`strcasestr`) for core CLI commands and prayers, and expose critical side-effect data (like logs) directly within the user interface.
