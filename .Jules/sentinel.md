## 2026-03-03 - Insecure Input Validation and Weak File Permissions
**Vulnerability:** Use of `strstr` for authentication and command matching allowed bypass via substring injection. Lack of default file permission restrictions (umask) left log files potentially over-permissive.
**Learning:** `strstr` checks for substrings, which is insufficient for security-critical string comparisons where exact matches are required. `fgets` also leaves trailing newlines that must be handled.
**Prevention:** Use `strcmp` or `strcasecmp` for exact matching after normalizing input (trimming whitespace and newlines). Set `umask(0077)` at program startup to ensure secure default permissions for all created files.
