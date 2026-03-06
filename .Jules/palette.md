## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Interrupt Handling in CLI Monitoring Loops
**Learning:** For terminal applications with persistent monitoring loops, implementing custom SIGINT (Ctrl+C) handling allows users to exit the loop and return to a main menu without terminating the entire process, significantly improving the interactive flow and preventing accidental data loss or frustration.
**Action:** Implement a global flag and signal handler for SIGINT in monitoring loops to enable a "retreat" path instead of a hard exit.
