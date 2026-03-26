## 2026-02-19 - Enhanced CLI Visibility and Accessibility
**Learning:** In CLI environments, pairing ANSI color codes with explicit textual labels (e.g., [SECURE], [CRITICAL]) significantly improves both glanceability for power users and accessibility for users with color vision deficiencies or non-color terminals.
**Action:** Always include textual state indicators alongside color-coded UI elements in terminal applications.

## 2026-03-25 - Preventing CLI Layout Jitter with Fixed-Width Formatting
**Learning:** In terminal UIs, dynamic text (like status labels or counters) can cause the entire interface to "jitter" or shift if their length changes. Using fixed-width format specifiers (e.g., `%-8s`) ensures consistent horizontal alignment of subsequent UI elements, providing a much smoother and more professional user experience.
**Action:** Use fixed-width formatting for all dynamic text in CLI visualizations to maintain layout stability.
