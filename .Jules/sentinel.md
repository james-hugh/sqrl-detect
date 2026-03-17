# Sentinel Security Journal
## 2026-03-12 - Initial Security Hardening
**Vulnerability:** TOCTOU (Time-of-check to time-of-use) in directory creation.
**Learning:** Using `stat` then `mkdir` allows a race condition where a malicious actor could create the directory or a symlink between the checks.
**Prevention:** Use atomic `mkdir` and check `errno == EEXIST`.
