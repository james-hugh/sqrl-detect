## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-21 - Persistent Menu and Settings Architecture
**Learning:** Implementing a persistent main menu loop and a dedicated settings sub-menu significantly improves user flow and feature discoverability in CLI tools, allowing for multiple interactions without re-authentication or restart.
**Action:** Use a `while(1)` loop for main application entry points and encapsulate configuration in a settings menu to maintain a clean primary interface.
