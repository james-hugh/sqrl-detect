## 2026-03-31 - Secure File Creation Defaults
**Vulnerability:** The application created log files and directories with default system permissions (e.g., 664), potentially allowing other users on the system to read sensitive "holy scrolls" or inject fake events.
**Learning:** Using `stat` to check for directory existence before calling `mkdir` creates a TOCTOU (Time-of-Check to Time-of-Use) race condition.
**Prevention:** Use `umask()` to set process-wide restrictive defaults and handle `mkdir` errors by checking `errno == EEXIST` for more atomic and robust directory creation.
