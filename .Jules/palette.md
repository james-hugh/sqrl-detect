## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-27 - Persistence in CLI Failure States
**Learning:** For CLI tools that might be launched from a GUI (like Windows ME), terminal windows often close immediately upon process exit. Adding a "Press Enter to continue" prompt on failure states ensures the user has time to read the error message or status indicator.
**Action:** Implement a manual "Press Enter" wait using `fgets` before exiting on critical user errors or authentication failures.
