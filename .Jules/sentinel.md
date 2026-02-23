## 2026-02-23 - Secure File Creation and Precise Authentication
**Vulnerability:** Default file permissions might create sensitive log files with overly broad access (e.g., 0644). Also, using `strstr` for authentication allows "GLORY BE" to be accepted even if surrounded by other text.
**Learning:** Using `umask(0077)` ensures all files created by the process are restricted to the owner by default. Using `strcmp` after `normalize_input` ensures authentication tokens must match exactly.
**Prevention:** Always set a restrictive `umask` at process start and prefer exact string comparison for security-sensitive inputs.
