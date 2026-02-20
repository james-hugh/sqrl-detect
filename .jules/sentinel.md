## 2026-02-20 - Improved Authentication and Logging
**Vulnerability:** Weak authentication using substring matching (`strstr`) and lack of security audit logs.
**Learning:** Using `strstr` for authentication can lead to bypasses (e.g., if the user enters "GLORY BE, HAHA"). Exact matching with `strcmp` after proper input cleaning is essential.
**Prevention:** Always use exact string matching for passwords or sacred prayers. Implement robust logging for all authentication attempts (initiated, failed, successful) to monitor for brute-force or unauthorized access.
