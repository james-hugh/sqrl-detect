## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-31 - Polishing CLI Visual Stability and Branding
**Learning:** Horizontal "jitter" caused by variable-length text labels in a CLI can be distracting and make the UI feel unpolished. Using fixed-width format specifiers (e.g., %-8s) ensures that the layout remains stable even as statuses change.
**Action:** Always use fixed-width formatting for status indicators and data values in real-time CLI visualizations to maintain visual alignment.
