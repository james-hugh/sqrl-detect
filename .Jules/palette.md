## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-12 - Centralized UI Theming and iconography
**Learning:** Hardcoding ANSI escape codes and emojis throughout the logic makes the codebase difficult to maintain and inconsistent.
**Action:** Use UI macros (e.g., `UI_MENU_HEADER`, `UI_AUTH_SUCCESS`) to centralize styling and ensure a consistent "Palette" across the application. Use confirmed acceptable emojis like 🕹️, 💀, and ✅.
