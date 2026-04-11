## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-08 - Improving CLI Input Accessibility and Feedback
**Learning:** For command-line interfaces, case-insensitive string matching significantly reduces user friction and accessibility barriers. Additionally, immediate visual confirmation (like a green [√]) after multi-step authentication processes provides essential positive reinforcement.
**Action:** Use `strcasestr` for command parsing where appropriate and provide clear, color-coded success indicators for incremental progress.
