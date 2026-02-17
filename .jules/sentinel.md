# Sentinel Security Journal

## 2026-02-17 - Strengthening Authentication and Log Security
**Vulnerability:** Substring matching (strstr) in authentication could allow bypasses. Insecure log file permissions could expose sensitive monitoring data.
**Learning:** Exact matching with strcmp after newline stripping is necessary for secure authentication. Audit logs must track all attempts. umask(0077) ensures fail-secure log creation.
**Prevention:** Always use strcmp for credentials and set restrictive umask before creating sensitive files.
