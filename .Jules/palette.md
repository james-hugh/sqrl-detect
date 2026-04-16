## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-15 - Forgiving CLI Input Patterns
**Learning:** Case-insensitive string matching for primary CLI commands and authentication prayers significantly reduces user frustration from minor typing errors. Additionally, introducing brief artificial delays and explicit "Initializing" messages during screen transitions prevents critical feedback (like success messages) from being instantly cleared, improving perceived reliability and system transparency.
**Action:** Implement case-insensitive input handling for all CLI prompts and ensure screen transitions preserve prior feedback long enough to be read.
