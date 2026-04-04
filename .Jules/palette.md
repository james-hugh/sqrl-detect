## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-03 - Prevent Horizontal Layout Jitter in CLI UIs
**Learning:** When displaying dynamic textual or numeric values in a terminal UI, using fixed-width format specifiers (e.g., `%-8s` for strings, `%3d` for integers) prevents horizontal layout shifting ("jitter") when the content length changes. This results in a much more stable and professional-looking interface.
**Action:** Use fixed-width format specifiers for all dynamic values in CLI headers and status indicators.
