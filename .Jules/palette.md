## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-05 - Forgiving Input and Graceful Interrupts in CLI
**Learning:** Robust CLI UX requires "forgiving" input handling (whitespace trimming, case-insensitivity) and graceful interrupt management (handling SIGINT/Ctrl+C) to prevent accidental process termination and allow users to return to a known state (like a main menu).
**Action:** Implement input normalization and signal handling to facilitate a "retreat" rather than a "crash" experience in interactive tools.
