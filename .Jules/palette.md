## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Signal Handling in Interactive Loops
**Learning:** Implementing a custom SIGINT (Ctrl+C) handler to toggle a control flag allows interactive monitoring loops to be interrupted gracefully, returning the user to a main menu instead of abruptly terminating the process and losing session state.
**Action:** Use `volatile sig_atomic_t` flags and `signal()` to manage state transitions in long-running CLI loops.
