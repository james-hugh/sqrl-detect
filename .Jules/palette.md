## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-02-19 - Visual Feedback in Multi-Step CLI Processes
**Learning:** For multi-step input sequences (like authentication prayers), providing immediate, positive feedback after each successful step reduces user uncertainty and confirms the system state. Additionally, explicit `fflush(stdout)` is necessary in C CLI apps to ensure prompts without newlines are visible before blocking for input.
**Action:** Use incremental feedback messages and ensure proper buffer flushing for all interactive CLI prompts.
