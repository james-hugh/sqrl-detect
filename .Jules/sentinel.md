## 2025-03-02 - Authentication Bypass via Substring Matching
**Vulnerability:** User could bypass the "GLORY BE" prayer requirement by entering any string containing the prayer as a substring (e.g., "I HATE GLORY BE").
**Learning:** Using `strstr` for authentication matching on user-provided input is dangerous as it allows for partial match exploits.
**Prevention:** Use `strcmp` for exact matching after normalizing input (stripping newlines and whitespace) to ensure only the intended secret or prayer is accepted.
