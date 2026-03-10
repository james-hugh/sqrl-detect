## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Interrupt Handling in CLI Menus
**Learning:** For interactive CLI applications with persistent monitoring loops, implementing a custom SIGINT handler allows users to return to the main navigation menu using Ctrl+C instead of terminating the entire process, creating a more seamless and professional UX.
**Action:** Use signal handlers and state flags to manage transitions between long-running operational modes and command menus.
