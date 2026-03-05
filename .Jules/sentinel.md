## 2026-03-05 - Insecure Input Validation in Authentication
**Vulnerability:** The authentication mechanism used `strstr()` to check for a sacred prayer, allowing users to bypass the check by providing the required phrase anywhere in the input (e.g., "NOT GLORY BE" or "GLORY BE --force-admin").
**Learning:** Using substring matching for credentials or command validation is a common pattern for "lazy" matching that introduces significant security risks. Exact matching with `strcmp()` after proper sanitization is required for secure authentication.
**Prevention:** Always use exact string comparison for secrets, passwords, or critical commands. Sanitize user input by stripping whitespace and newlines before comparison to ensure reliability without sacrificing security.
