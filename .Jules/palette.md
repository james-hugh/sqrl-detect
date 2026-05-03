## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-05-03 - Systematic CLI Refactoring and Command Persistence
**Learning:** Transforming a linear script into a persistent command loop with a centralized header (`print_header`) and clear status indicators ([SUCCESS], [EXITED]) provides a more "professional" feel and better UX. Additionally, ensuring all input buffers are wiped with `secure_memzero` and checking `fgets` return values prevents security leaks and compiler warnings.
**Action:** Implement persistent loops for interactive CLIs and use centralized UI drawing functions to maintain a consistent aesthetic.
