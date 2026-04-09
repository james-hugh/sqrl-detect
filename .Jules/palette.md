## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-04-08 - Eliminating Terminal UI Jitter
**Learning:** Using fixed-width format specifiers (e.g., `%-8s` for strings, `%3d` for integers) in terminal UIs prevents horizontal layout shifting ('jitter') when dynamic content lengths change, leading to a more stable and professional-feeling interface.
**Action:** Use fixed-width padding for all dynamic text elements in CLI status bars or meters.
