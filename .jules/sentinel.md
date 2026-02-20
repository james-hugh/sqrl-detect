## 2026-02-20 - Authentication Substring Bypass
**Vulnerability:** Use of `strstr()` for authentication string matching allowed partial or wrapped matches (e.g., "FOO GLORY BE BAR") to bypass the intended security check.
**Learning:** Substring matching is inherently insecure for authentication. Exact string comparison must be used to ensure only the authorized secret is accepted.
**Prevention:** Always use `strcmp()` (or similar exact-match functions) for sensitive string comparisons, and ensure input is properly normalized (e.g., stripping newlines with `strcspn()`) before comparison.
