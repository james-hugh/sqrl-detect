# 🛡️ Sentinel's Journal

## 2026-03-24 - Hardened Log Permissions and Threat Meter Clamping

**Vulnerability:**
The application was creating logs and a log directory with default permissions, which could potentially allow other users on the system to read sensitive "holy scrolls." Additionally, the `print_threat_meter` function lacked defensive clamping for its `level` parameter, which could lead to out-of-bounds reads on static visualization strings if called with unexpected values.

**Learning:**
Always use `umask` at the start of security-sensitive applications to ensure all subsequently created files and directories have the most restrictive permissions by default. In C, always validate or clamp input parameters that are used to index or calculate offsets into buffers, even if those buffers are static strings.

**Prevention:**
Integrate `umask(0077)` in the system initialization phase. Implement defensive clamping for all parameters used in visualization or data processing logic.
