## 2026-02-18 - Authentication Bypass via Substring Matching
**Vulnerability:** The `authenticate_user` function used `strstr()` to verify the sacred prayer, which allowed users to bypass authentication by providing any string containing the required phrase (e.g., "I HATE GLORY BE").
**Learning:** Using substring matching for security-critical comparisons is a common but dangerous pattern. Input normalization (like stripping newlines) must be paired with exact string comparison.
**Prevention:** Always use `strcmp()` or equivalent exact-match functions for authentication. Ensure inputs are properly sanitized and normalized before comparison.
