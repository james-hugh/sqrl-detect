# 🛡️ Sentinel's Security Journal

## 2026-03-20 - TOCTOU and Insecure File Permissions in STNM3K
**Vulnerability:** The application used a "check-then-act" pattern for directory creation (`stat` followed by `mkdir`), creating a TOCTOU (Time-of-Check to Time-of-Use) race condition. Additionally, it lacked a global `umask` setting, potentially creating logs with overly permissive default permissions if the environment was misconfigured.

**Learning:** Checking for file existence before creation is inherently racey in multi-user environments. A malicious actor could potentially swap the directory for a symbolic link between the `stat` and `mkdir` calls. Furthermore, defensive programming in security tools should always enforce the principle of least privilege for its own data.

**Prevention:**
1. Always use `umask()` during system initialization to set a secure baseline for all file and directory creation.
2. Use atomic operations for file/directory creation (e.g., `mkdir` or `open` with `O_CREAT | O_EXCL`) and handle the `EEXIST` error instead of checking beforehand.
3. Clamp all inputs used in buffer calculations, even if they appear to be internally generated, to prevent out-of-bounds reads.
