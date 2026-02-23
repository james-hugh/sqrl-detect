## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-19 - Visual Hierarchy and Prompt Responsiveness in CLI
**Learning:** In CLI environments, thematic headers and semantic color-coding of menu options (e.g., Green for primary actions, Red for exit/danger) establish a clear visual hierarchy. Additionally, calling `fflush(stdout)` after prompts that do not end in a newline is critical to ensure they are rendered before the application blocks for user input.
**Action:** Use thematic headers and semantic colors for menu structures, and always flush stdout after prompt strings.
