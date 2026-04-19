
## 2026-04-19 - Atomic Directory Creation and umask Hardening
**Vulnerability:** TOCTOU (Time-of-Check to Time-of-Use) race condition during directory creation and insecure default file permissions.
**Learning:** Checking for directory existence before creating it allows for race conditions; using umask(0077) ensures restricted permissions are applied immediately upon file/directory creation.
**Prevention:** Call mkdir directly and handle EEXIST via errno; use umask to set strict default permissions for the entire process.
