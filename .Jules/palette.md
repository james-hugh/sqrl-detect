## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-04 - Graceful Interrupts in CLI UX
**Learning:** For interactive CLI applications with continuous monitoring loops, providing a way to return to the main menu (e.g., via SIGINT/Ctrl+C) instead of terminating the process creates a significantly more pleasant and less frustrating user experience.
**Action:** Use signal handling to allow users to gracefully escape sub-modes without losing application state.
