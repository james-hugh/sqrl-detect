## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-05-02 - Resilient and Forgiving CLI Inputs
**Learning:** A "forgiving" interface that handles case-insensitive string matching and provides a persistent command loop significantly reduces user frustration from minor typos or unintentional Caps Lock usage, especially in high-stakes simulated environments.
**Action:** Implement case-insensitive input parsing and wrap main interaction loops to prevent premature application exit on invalid input.
