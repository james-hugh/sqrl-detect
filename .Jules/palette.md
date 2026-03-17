## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-12 - Clean Input Handling
**Learning:** Mixing \`getchar()\` and \`fgets()\` can lead to inconsistent UI behavior (like requiring double-Enter) if the input buffer isn't managed carefully.
**Action:** Stick to a single input method (like \`fgets\`) for prompts to ensure a smooth and predictable user experience.
