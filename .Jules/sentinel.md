# Sentinel's Journal

## 2026-05-04 - Authentication Bypass via Partial Match
**Vulnerability:** The `authenticate_user` function used `strstr` to verify the sacred prayer, allowing any input containing "GLORY BE" (e.g., "NOT GLORY BE") to pass.
**Learning:** `strstr` is unsuitable for exact string verification in security contexts as it only checks for substrings.
**Prevention:** Always use `strcmp` with proper input sanitization (like trimming newlines with `strcspn`) for exact credential matches.
