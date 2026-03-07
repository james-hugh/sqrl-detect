## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Interrupts in Interactive CLI Loops
**Learning:** Implementing a global `volatile sig_atomic_t` flag and a custom `SIGINT` handler allows long-running CLI monitoring loops to be gracefully interrupted by Ctrl+C, enabling a return to the main menu instead of total process termination. This significantly improves the micro-UX of persistent command-line tools.
**Action:** Use signal-based state management to allow users to "exit" sub-menus or loops back to a stable navigation state.
