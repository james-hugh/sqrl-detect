## 2026-02-21 - Authentication Bypass via Substring Matching
**Vulnerability:** Use of `strstr()` for checking authentication credentials allowed users to bypass the check by providing a string that contained the required secret but also included arbitrary trailing data (e.g., "SECRET[TRASH]").
**Learning:** Substring matching functions are dangerous for authentication logic as they do not enforce a strict 1:1 match of the expected credential, leading to bypasses in environments where input normalization is incomplete or where additional data can be appended.
**Prevention:** Always use exact string comparison (`strcmp()`) for authentication and authorization checks. Ensure all user input is normalized (e.g., stripping trailing newlines with `strcspn()`) before performing comparisons.
