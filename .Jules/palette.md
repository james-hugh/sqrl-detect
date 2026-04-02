## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-31 - Eliminating Terminal UI Jitter
**Learning:** Terminal UI "jitter"—where elements shift horizontally due to varying text lengths—creates a jarring user experience and can disrupt a user's visual focus. Using fixed-width format specifiers (e.g., `%-8s`, `%3d%%`) ensures visual stability and a more professional, "solid" feel for CLI dashboards.
**Action:** Use fixed-width padding for all dynamic text and numerical elements in CLI visualizations to maintain consistent alignment.
