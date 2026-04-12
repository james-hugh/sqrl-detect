## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-12 - Forgiving CLI Interaction Patterns
**Learning:** CLI applications feel significantly more "polished" and user-friendly when they employ "forgiving" interaction patterns: case-insensitive input handling and input validation loops. This prevents minor typos from causing frustrating app terminations and reduces the cognitive load on the user.
**Action:** Implement case-insensitive string matching and wrap main menu interactions in persistent loops to handle invalid inputs gracefully.
