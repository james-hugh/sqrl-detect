# SENTINEL'S JOURNAL - CRITICAL LEARNINGS ONLY

## 2025-05-14 - Insecure Authentication Match
**Vulnerability:** Substring matching using `strstr` on user input allowed for authentication bypass.
**Learning:** Using `strstr` or similar partial matching functions for authentication checks is inherently insecure as it allows attackers to bypass checks by including the required string within a larger, non-conforming input.
**Prevention:** Always use exact string matching (e.g., `strcmp`) after normalizing user input (trimming whitespace and newlines) for authentication and critical control flow decisions.
