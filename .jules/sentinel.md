## 2026-02-18 - Defense in Depth and Audit Logging

**Vulnerability:** Weak authentication using substring matching (`strstr`) and potential exposure of sensitive log files due to default file permissions.

**Learning:** Authentication should always use exact string matching (`strcmp`) after input normalization to prevent bypasses. Furthermore, implementing 'Defense in Depth' requires ensuring that all process-created files are secure by default using `umask(0077)`. Audit logging of all authentication events is critical for detecting brute-force or unauthorized access attempts.

**Prevention:** Replaced `strstr` with `strcmp` in `authenticate_user`, added `umask(0077)` to `main`, and implemented comprehensive audit logging for all authentication states.
