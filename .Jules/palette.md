## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Interrupt Handling in Persistent CLI Menus
**Learning:** Providing a way to return to a main menu via a standard interrupt (SIGINT/Ctrl+C) rather than terminating the entire process creates a much smoother and more forgiving user experience for interactive terminal tools.
**Action:** Use signal handlers to toggle state flags in long-running CLI loops to allow graceful exits back to parent menus.
