# Sentinel Security Journal

## 2026-04-22 - Memory and File Permission Hardening
**Vulnerability:** Sensitive input (sacred prayer) was left in memory after authentication, and log files were created with default (often overly permissive) permissions.
**Learning:** Default file creation and standard memory management often fail to meet "Defense in Depth" requirements, especially in simulated high-security environments like STNM3K.
**Prevention:** Use `umask` to enforce strict file permissions globally and implement `secure_memzero` using `volatile` pointers to prevent compiler optimization from skipping memory wipes.
