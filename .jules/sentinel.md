## 2026-02-28 - [Authentication Bypass via Substring Matching]
**Vulnerability:** Insecure authentication matching using `strstr` on user input allows bypass via substring injection (e.g., 'I HATE GLORY BE').
**Learning:** Using substring search functions like `strstr()` for sensitive comparisons is dangerous because it ignores context. User input often includes newlines from `fgets()`, which might have been why `strstr()` was used to "ignore" the newline.
**Prevention:** Use exact matching with `strcmp()` after properly normalizing/cleaning user input (e.g., stripping whitespace and newlines). Always implement audit logging for security-sensitive events like authentication.
