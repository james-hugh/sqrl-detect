## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-05-03 - Interactive Terminal Dashboards and Persistent Menus
**Learning:** Moving from linear execution to a persistent `while(1)` command loop with a centralized header and menu significantly improves the "command center" feel of security simulations.
**Action:** Implement persistent menu loops in CLI tools to allow multiple operations without restarts, and use screen-clearing to maintain a clean dashboard aesthetic.
