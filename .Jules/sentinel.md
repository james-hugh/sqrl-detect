## 2025-03-06 - Insecure Authentication via Substring Matching
**Vulnerability:** The application used `strstr()` to verify authentication phrases and menu commands, allowing bypasses via substring injection (e.g., "GLORY BEYOND" matching "GLORY BE").
**Learning:** Using substring matching for security-critical string verification is inherently fragile. User input often contains trailing newlines (from `fgets`) or extra whitespace that must be handled before performing an exact comparison.
**Prevention:** Always normalize user input (strip whitespace/newlines) and use exact matching functions like `strcmp()` or `strcasecmp()` for credentials and command routing.
