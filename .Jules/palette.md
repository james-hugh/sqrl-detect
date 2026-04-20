## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-20 - CLI UI Stability via Fixed-Width Formatting
**Learning:** Dynamic values in terminal UIs (like percentages or status labels) can cause "horizontal jitter" if their string length changes, which is distracting and makes the UI feel unpolished.
**Action:** Use fixed-width format specifiers (e.g., `%-8s`, `%3d%%`) in `printf` to ensure terminal UI elements maintain a consistent layout regardless of value length.
