## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-25 - Preventing CLI UI Jitter with Fixed-Width Formatting
**Learning:** In interactive CLI applications with frequently updating status lines, variable-length text (like percentages or status labels) causes horizontal "jitter" as elements shift left and right. This is visually distracting and makes the interface feel unstable.
**Action:** Use fixed-width format specifiers (e.g., `%-8s` for strings, `%3d%%` for percentages) to reserve space and maintain consistent horizontal alignment of UI elements.
