## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-05-05 - Consistent Input Handling and Menu Polish
**Learning:** Inconsistent input handling (e.g., stripping newlines in some functions but not others) can lead to subtle bugs and UI glitches. Additionally, providing a structured menu with version/platform metadata improves professional feel.
**Action:** Always strip trailing newlines immediately after `fgets` and use decorative ASCII boxes with metadata footers for primary menus.
