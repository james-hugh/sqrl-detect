## 2026-04-04 - Static buffer and precision specifier for ASCII rendering
**Learning:** Using `%.*s` with a static character buffer significantly reduces `printf` overhead when rendering repetitive patterns (like ASCII bars) compared to character-by-character loops.
**Action:** Always prefer bulk character output over character-at-a-time `printf` calls for UI elements.
