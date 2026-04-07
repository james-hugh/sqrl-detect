## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-06 - Case-Insensitive CLI Commands and Enhanced Feedback
**Learning:** Forgiving user input via case-insensitive matching (e.g., `strcasestr`) reduces frustration in CLI environments where users may not strictly follow capitalization rules. Additionally, adding immediate, color-coded visual symbols (like a green [√]) for success provides instant positive reinforcement.
**Action:** Implement case-insensitive matching for primary user commands and use clear, colored symbols for success/failure feedback in CLI tools.
