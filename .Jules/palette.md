## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-04 - Persistent Command Loop and Graceful Interrupts
**Learning:** For interactive CLI tools, a persistent menu loop combined with graceful signal handling (`SIGINT`) provides a significantly better user experience than a single-shot execution. It allows users to explore multiple features (e.g., diagnostics, logs) without re-authenticating.
**Action:** Implement persistent `while` loops for main menus and use `sig_atomic_t` flags with custom signal handlers to allow users to interrupt long-running tasks without terminating the application.
