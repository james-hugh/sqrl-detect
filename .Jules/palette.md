## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Graceful Navigation and Signal Handling in CLI
**Learning:** In interactive CLI applications, providing a way to "back out" of long-running or monitoring states without killing the entire process is critical for a smooth user experience. Using signal handlers (like SIGINT) to return to a persistent main menu transforms a one-shot utility into a much more usable "command center" feel.
**Action:** Implement SIGINT handlers and persistent main loops in interactive terminal tools to allow graceful state transitions.
