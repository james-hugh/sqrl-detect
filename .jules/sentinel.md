## 2026-02-19 - Authentication Hardening and Audit Logging
**Vulnerability:** Substring matching (`strstr`) was used for authentication, allowing bypasses with prefixed/suffixed input. Also, missing audit logs for authentication attempts and insecure default file permissions.
**Learning:** Authentication must always use exact matching (`strcmp`) after careful input normalization (e.g., stripping newlines). Security-critical events must be audit-logged to provide a trail for incident response.
**Prevention:** Enforce exact string matching for all security checks. Use `umask` to set restrictive default permissions for all process-created files. Implement comprehensive logging for all authentication lifecycle events.
