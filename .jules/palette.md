## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-24 - Animated Progress Feedback and Menu Hierarchy
**Learning:** Using `\r` with `usleep` for progress bars provides immediate visual feedback for long-running simulated tasks, improving perceived responsiveness. Semantic color hierarchies in menus (e.g., Green for primary actions, Red for exit) help guide user attention.
**Action:** Implement progress indicators for long-running operations and use consistent color coding for menu actions.
