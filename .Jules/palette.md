## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-23 - Thematic Main Menu and Command Normalization
**Learning:** A clear, thematic main menu with semantic color grouping (e.g., Green for primary actions, Cyan for headers) improves user orientation after the authentication phase. Additionally, normalizing user input (trimming whitespace/newlines) prevents frustrating command rejection due to invisible characters.
**Action:** Implement a standard `normalize_input` helper for all CLI input and use a consistent color hierarchy for menu navigation.
