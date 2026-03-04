## 2026-03-04 - Insecure Authentication and Command Matching
**Vulnerability:** The `authenticate_user` function used `strstr` on un-normalized user input, allowing authentication bypass via substring injection (e.g., "GLORY BE EXTRA"). Additionally, menu selection lacked input normalization, making it fragile.
**Learning:** Security-critical string comparisons must always be performed on normalized input (trimmed whitespace/newlines) using exact matching (`strcmp`) or robust case-insensitive matching (`strcasecmp`) instead of substring searches.
**Prevention:** Always implement a robust `normalize_input` utility and prefer `strcmp` over `strstr` for authentication and command parsing.
