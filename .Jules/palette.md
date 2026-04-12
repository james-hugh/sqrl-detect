## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-12 - Case-Insensitive CLI Interactions and Feedback
**Learning:** CLI usability is greatly enhanced by implementing case-insensitive string matching for primary commands and authentication prompts, reducing friction for users. Providing immediate visual confirmation (e.g., green "[√] ACCEPTED" labels) after significant state transitions provides clear feedback and reduces cognitive load.
**Action:** Implement `strcasestr` or equivalent for user-facing string matching and use ANSI-colored status labels for critical feedback.
