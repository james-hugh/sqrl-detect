## 2026-04-18 - Log Permission Hardening
**Learning:** Using `umask(0077)` before creating directories and files ensures that sensitive logs are only accessible by the owner by default, fulfilling the "secure by default" principle.
**Action:** Always set a restrictive umask when initializing applications that handle sensitive user data or logs.
