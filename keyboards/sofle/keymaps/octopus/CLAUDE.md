# Octopus keymap

Personal Sofle v2 keymap (two rotary encoders), forked from `hcastilho`
to experiment with ergonomic improvements.

## Hardware & usage

- **Keyboard:** Sofle v2, two rotary encoders
- **Used on:** macOS (work laptop), Linux (desktop), Windows (gaming desktop)
- **Origin:** started from QMK default Sofle keymap with minor tweaks; no
  longer satisfied with the setup, want a more deliberate ergonomic layout

## Compile

```
qmk compile -kb sofle/rev1 -km octopus
```

## Improvement backlog

Suggestions grouped by category. Items marked `[done]` are already
implemented on this keymap; the rest are open.

### Code cleanup

- **[done] Replace custom word-nav keycodes with OS detection**
  Decision: prefer per-OS muscle memory over physical key remapping —
  swapping Ctrl/GUI between OSes was more confusing than helpful (e.g.
  Ctrl+C still ends a terminal command on Mac too). `CG_TOGG` removed from
  ADJUST. `KC_PRVWD`/`KC_NXTWD`/`KC_LSTRT`/`KC_LEND` now use
  `detected_host_os()` (via `OS_DETECTION_ENABLE`) to auto-pick Alt vs
  Ctrl and Cmd+arrow vs Home/End. OLED now displays detected OS.

- **[done] Drop dead clipboard handlers**
  The `KC_COPY/KC_CUT/KC_PASTE` `#defines` (Ctrl+Shift+C/X/V) were
  shadowed by `process_record_user` handlers that sent plain Ctrl+C/X/V,
  so the Shift was never sent. Removed the defines and the four handlers;
  keymap now uses native `LCTL(KC_C)` etc. directly. Per-OS muscle memory
  preference applies — no Mac/Win branching for these keys.

- **[done] Drop `KC_4SPC`**
  Removed along with the `DF` combo that triggered it. Tab on the thumb
  (planned) covers indentation.

- **Refactor encoder alt-tab boilerplate**
  Four near-identical branches in `encoder_update_user`. Extract a helper.

### Ergonomic experiments

- **[done] Home row mods (GACS) on `_QWERTY`**
  A/S/D/F = GUI/Alt/Ctrl/Shift on hold. Mirrored on J/K/L/;.
  Tuned with `TAPPING_TERM 200`, `HOLD_ON_OTHER_KEY_PRESS`,
  `QUICK_TAP_TERM 0`. See `config.h`.

- **[done] Replace Colemak layer with `_GAMING`**
  Plain QWERTY, no tap-hold, no HRM — games see real Ctrl/Alt/Shift/Space
  instantly. Toggle with `TG(_GAMING)` from ADJUST layer (the key where
  Colemak used to be).

- **[done] Layer-tap on thumbs (symmetric)**
  Left inner: `LT(_LOWER, KC_SPC)` — tap=Space, hold=LOWER.
  Right inner: `LT(_RAISE, KC_ENT)` — tap=Enter, hold=RAISE.
  Freed slots: left=`KC_TAB`, right=`KC_BSPC`. Gaming layer keeps plain
  Space/Enter and standalone `MO(_LOWER)`/`MO(_RAISE)` so games see
  instant keys with no tap-hold delay.
  *Watch out:* fast typing can falsely trigger the layer (e.g. `space + c`
  too quick → `c` fires on LOWER as `#`). If it misbehaves, add
  `TAPPING_TERM_PER_KEY` to give space/enter a longer term, or remove
  `HOLD_ON_OTHER_KEY_PRESS` for those two keys.

- **[done] Drop `JK`→Esc and `DF`→4-spaces combos**
  Removed entirely (along with `COMBO_ENABLE` and `KC_4SPC`). Esc and Tab
  will live on freed thumb slots once HRM makes thumb mods redundant.

- **Caps Word on RAISE**
  Already enabled via `BOTH_SHIFTS_TURNS_ON_CAPS_WORD` /
  `DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD`. Could also expose `CW_TOGG`
  explicitly on RAISE in place of plain `KC_CAPS`.

- **Visual indicator for gaming mode**
  Underglow color or OLED highlight when `_GAMING` is active. OLED already
  prints "Game" — could add RGB.

### Bigger redesigns (later)

- **Symbols layer designed around code**
  Current LOWER is a numpad/symbol mishmash. Design around most-typed
  programming symbols (`()`, `{}`, `=>`, `->`) on home row.

- **Dedicated nav layer under right hand**
  Arrows on HJKL accessible via a thumb layer-hold while keeping HRM
  available. Reduces RAISE-layer trips.

- **Hyper key**
  Free a thumb (after LT-on-space) and bind `KC_HYPR`. Pair with
  Hammerspoon / AutoHotkey / sxhkd for OS-level shortcuts that never
  collide with app shortcuts.

## Tuning notes

If after a few days of using HRM:

- Accidental mods mid-word → raise `TAPPING_TERM` to 220, or switch
  `HOLD_ON_OTHER_KEY_PRESS` for `CHORDAL_HOLD` (only triggers hold for
  opposite-hand chords).
- Mods feel sluggish → drop to 180 or 170.
- Pinky GUI annoying → swap mod order or drop GUI entirely.
