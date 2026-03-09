## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Signal Interrupts in CLI Menus
**Learning:** Handling SIGINT (Ctrl+C) within persistent CLI loops allows users to return to a parent menu or "retreat" gracefully without terminating the entire application process, providing a much more forgiving user experience.
**Action:** Implement signal handlers and global flags to manage state transitions during long-running or interactive CLI operations.
