# Sentinel Journal

## 2025-02-22 - Securing Authentication and Logging
**Vulnerability:** Substring-based authentication bypass and insecure default file permissions.
**Learning:** Using `strstr()` for authentication allows attackers to bypass checks by including the required string anywhere in their input. Additionally, lack of explicit `umask` can lead to overly permissive log files.
**Prevention:** Use `strcmp()` with exact matching after stripping newlines for authentication. Set `umask(0077)` at process start to ensure secure-by-default file permissions.
