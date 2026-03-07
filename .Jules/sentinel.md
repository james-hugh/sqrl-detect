## 2026-03-07 - Insecure Substring Authentication Bypass
**Vulnerability:** Use of `strstr` for authentication and command matching on unsanitized user input allowed bypasses via substring injection (e.g., "WRONG GLORY BE" matched "GLORY BE").
**Learning:** `strstr` is insufficient for precise command or credential validation as it doesn't account for surrounding characters or input noise like newlines.
**Prevention:** Always normalize input (trim whitespace/newlines) and use exact matching functions like `strcmp` or `strcasecmp` for command and authentication logic.
