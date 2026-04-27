## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-25 - CLI Input Robustness and Accessibility
**Learning:** Forgiving input mechanisms (like case-insensitivity) combined with immediate textual feedback (e.g., [ACCEPTED]) makes CLI applications feel significantly more responsive and accessible. Textual state indicators provide a crucial fallback for users in non-color terminals or with vision impairments.
**Action:** Implement case-insensitive command parsing and pair all color-coded feedback with descriptive textual labels.
