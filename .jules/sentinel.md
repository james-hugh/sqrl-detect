## 2026-02-24 - Secure File Defaults via Umask
**Learning:** Calling `umask(0077)` during system initialization ensures that all files created by the process (including logs and temporary artifacts) follow the principle of least privilege by default, protecting sensitive diagnostic data from unauthorized access.
**Action:** Always set a restrictive umask in security-focused CLI utilities.
