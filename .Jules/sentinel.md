## 2026-03-12 - Critical Security Hardening for STNM3K
**Learning:** Default file permissions and TOCTOU (Time-of-Check to Time-of-Use) race conditions are common vectors for local privilege escalation. Insecure directory creation can lead to symlink attacks.
**Prevention:**
1. Use `umask(0077)` to ensure all files created by the process are only readable/writable by the owner.
2. Replace `stat` + `mkdir` sequences with direct `mkdir` calls and check `errno == EEXIST` to atomize directory creation and prevent TOCTOU races.
