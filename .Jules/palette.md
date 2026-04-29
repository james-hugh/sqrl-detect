## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-27 - Input Forgiveness and Persistent Feedback
**Learning:** Making CLI inputs case-insensitive (forgiving input) and providing a 'Press Enter to exit' prompt on fatal errors significantly reduces user frustration and prevents accidental application termination.
**Action:** Implement case-insensitive parsing for critical commands and ensure error messages are readable by pausing before exit.
