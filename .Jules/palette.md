## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-19 - Graceful CLI Interrupt and Persistent Menu
**Learning:** For CLI tools, a graceful interrupt (e.g., SIGINT) that returns the user to a functional main menu rather than terminating the process improves session continuity and prevents the friction of re-authentication.
**Action:** Implement signal handlers for monitoring loops and wrap main logic in a persistent command loop.
