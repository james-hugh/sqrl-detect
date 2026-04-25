## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-23 - Case-Insensitivity and Immediate Feedback in CLI
**Learning:** For CLI tools, case-insensitive string matching significantly improves user accessibility by reducing errors caused by minor capitalization differences. Additionally, providing immediate, color-coded success indicators (e.g., [√] ACCEPTED) for multi-step processes like authentication provides essential reassurance and confirmation to the user.
**Action:** Implement case-insensitive command parsing and provide immediate visual success feedback for user inputs.
