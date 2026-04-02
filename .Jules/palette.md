## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-31 - Visual Branding and Layout Stability
**Learning:** Adding a themed ASCII banner and consistent decorative borders establishes a strong visual identity for CLI tools. Using fixed-width format specifiers (e.g., `%-8s`, `%3d%%`) in dynamic UI elements prevents horizontal 'jitter' and ensures a professional, stable interface during continuous updates.
**Action:** Standardize UI borders and use padded format specifiers for all real-time data displays in terminal applications.
