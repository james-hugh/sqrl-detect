## 2026-05-02 - Authentication Bypass via Partial String Matching
**Vulnerability:** Use of `strstr` for authentication allows bypassing checks if the required "secret" is part of a larger, non-matching input (e.g., "I REFUSE TO SAY GLORY BE" would pass if "GLORY BE" is searched for).
**Learning:** `strstr` is inappropriate for authentication as it only checks for substring existence, ignoring leading/trailing content. Exact matching is necessary for security tokens.
**Prevention:** Always use `strcmp` or similar exact matching functions after properly sanitizing (e.g., trimming newlines) the user input for authentication checks.
