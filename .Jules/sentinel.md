## 2025-03-09 - Insecure Input Matching in C CLI
**Vulnerability:** Use of `strstr` for authentication and command matching allowed for substring-based bypasses (e.g., "I HATE SQUIRRELS BUT GLORY BE" passing a "GLORY BE" check).
**Learning:** Interactive CLI apps often forget to normalize user input (strip whitespace/newlines) before comparison, and using substring matching instead of exact matching creates security gaps.
**Prevention:** Always normalize input using a utility function to trim whitespace/newlines and use exact string comparisons (`strcmp` or `strcasecmp`) for sensitive logic like authentication.
