## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-19 - Robust CLI Input Normalization
**Learning:** In CLI applications, user input often contains accidental trailing spaces or varying line endings (\r\n). Normalizing input by trimming both whitespace and newline characters makes the interface more forgiving and prevents frustrating authentication or command failures.
**Action:** Implement a dedicated normalization helper that handles both newlines and trailing spaces for all interactive prompts.
