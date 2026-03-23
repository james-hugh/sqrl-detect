## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-22 - UI Stability in CLI Monitoring Interfaces
**Learning:** Fixed-width formatting for dynamic text labels in terminal-based monitoring loops prevents "jittering" (horizontal shifting) of adjacent UI elements. This significantly reduces cognitive load and visual fatigue during long-term monitoring.
**Action:** Use explicit width padding (e.g., `%-8s`) for status indicators that vary in length to ensure layout stability.
