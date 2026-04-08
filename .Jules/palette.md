## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-07 - Case-Insensitive CLI Interaction
**Learning:** Implementing case-insensitive string matching for CLI commands significantly improves user experience by being "forgiving" to user input variation. This reduces friction, especially in repetitive or multi-step interactions, and makes the tool more accessible to users with different typing speeds or habits.
**Action:** Use case-insensitive matching (e.g., `strcasestr`) for primary CLI commands and authentication prompts.
