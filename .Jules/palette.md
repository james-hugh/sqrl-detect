## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-19 - Graceful Lifecycle Management in CLI Dashboards
**Learning:** For terminal-based monitoring tools or "dashboards," implementing a custom `SIGINT` handler allows users to return to a main menu instead of killing the process. This transforms the utility from a single-run script into a cohesive "application" experience.
**Action:** Use signal handling and persistent menu loops to manage transitions between monitoring states and interactive menus.
