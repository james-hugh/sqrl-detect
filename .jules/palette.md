## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-25 - Robust CLI Navigation and Signal Handling
**Learning:** CLI applications that claim to support "Ctrl+C to exit" but actually terminate the entire process can frustrate users. Implementing signal handlers for graceful transitions between app states provides a much smoother UX.
**Action:** Implement `SIGINT` handlers in long-running loops to allow users to return to main menus instead of exiting the application entirely.
