## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-31 - CLI Alignment and Visual Stability
**Learning:** Dynamic text lengths in CLI status updates (e.g., "SECURE" vs. "CRITICAL") cause horizontal "jitter" that distracts users and makes the interface feel unstable. Using fixed-width format specifiers ensures consistent layout and improves glanceability.
**Action:** Use fixed-width padding (e.g., `%-8s`, `%3d`) for all dynamic text elements in frequently updated CLI views.
