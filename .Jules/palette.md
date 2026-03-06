## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Monitoring Interrupts
**Learning:** In persistent CLI applications with blocking monitoring loops, capturing `SIGINT` (Ctrl+C) via a `volatile sig_atomic_t` flag allows the user to return to a parent menu instead of terminating the entire process. This provides a significantly more fluid and forgiving navigation experience.
**Action:** Use signal handlers to toggle state flags for graceful exits from blocking loops, ensuring original signal behaviors are restored upon loop termination.
