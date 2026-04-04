## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-04 - UI Stability via Fixed-Width Formatting
**Learning:** Terminal UI elements that update in-place (like progress bars or status meters) can cause distracting horizontal "jitter" if their component strings or numeric values change in length.
**Action:** Use fixed-width format specifiers (e.g., `%-8s`, `%3d`) in `printf` to ensure layout stability for dynamic CLI content.
