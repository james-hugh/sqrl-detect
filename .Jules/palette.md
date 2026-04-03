## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-03 - Eliminating Horizontal Jitter in CLI Displays
**Learning:** Dynamic text lengths and varying numeric digit counts in terminal UIs cause horizontal "jitter" as the surrounding layout elements (brackets, bars, etc.) shift position. This is visually distracting and makes the UI harder to read quickly.
**Action:** Use fixed-width format specifiers (e.g., `%-8s` for strings, `%3d` for integers) to reserve space for the maximum expected width of dynamic content, ensuring a stable and professional layout.
