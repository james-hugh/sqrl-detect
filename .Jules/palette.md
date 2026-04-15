## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-15 - Forgiving and Robust CLI Interaction Patterns
**Learning:** CLI users often make minor capitalization errors or mis-type menu numbers. Implementing case-insensitive string matching and persistent interaction loops (instead of immediate exits) significantly reduces user frustration and makes the application feel more "professional" and robust.
**Action:** Use case-insensitive matching for primary commands and wrap main interaction points in loops that handle invalid input gracefully with clear feedback.
