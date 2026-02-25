## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-19 - Robust CLI Input and Interaction Patterns
**Learning:** For interactive CLI applications, using `normalize_input` (trimming whitespace and newlines) combined with `strcasecmp` for menu selection significantly reduces user frustration from minor typing errors. Furthermore, explicit `fflush(stdout)` after prompts is essential for ensuring they are visible before input blocks, maintaining a smooth interactive flow.
**Action:** Always pair interactive prompts with `fflush(stdout)` and use robust input normalization and case-insensitive comparison for menu commands.
