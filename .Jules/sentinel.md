# Sentinel Journal

## 2026-02-27 - Substring Injection in Authentication
**Vulnerability:** The `authenticate_user` function used `strstr` to verify the sacred prayer "GLORY BE", which allowed authentication bypass via substring injection (e.g., "I HATE GLORY BE").
**Learning:** Using substring matching for security-critical input verification is insecure as it doesn't ensure an exact match.
**Prevention:** Always use exact matching (like `strcmp`) after normalizing input (trimming whitespace and newlines) for authentication and authorization checks.
