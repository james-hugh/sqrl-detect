## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Loop Termination in CLI
**Learning:** For interactive CLI monitoring tools, providing a way to return to the main menu (e.g., via SIGINT handling) instead of terminating the process improves user flow and prevents the frustration of restarting the application for every task.
**Action:** Implement signal handlers for long-running CLI loops to allow graceful navigation back to the primary interface.
