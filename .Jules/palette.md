## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful CLI Interrupt Handling
**Learning:** Implementing custom signal handlers for `SIGINT` (Ctrl+C) in persistent CLI monitoring loops allows users to return to a central menu rather than abruptly terminating the entire process. This provides a more fluid, cohesive user experience similar to "Back" navigation in a GUI.
**Action:** Use `volatile sig_atomic_t` flags and `signal.h` to manage state transitions in long-running CLI tasks.
