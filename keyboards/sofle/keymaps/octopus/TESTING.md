# Octopus keymap — test checklist

Flash both halves before starting. Test on each OS where applicable. Mark
issues inline so we can decide what to tune.

## Build & flash

- [ ] `qmk compile -kb sofle/rev1 -km octopus` — compiles with no errors
- [ ] Both halves flashed
- [ ] OLED on master half shows MODE / OS / LAYER

## OS detection

- [ ] Plug into **macOS** → OLED shows `MAC`
- [ ] Plug into **Linux** → OLED shows `LNX`
- [ ] Plug into **Windows** → OLED shows `WIN`
- [ ] Hot-swap between machines and verify OLED updates without reflashing

## Home row mods (QWERTY base layer)

Left hand: A=GUI, S=Alt, D=Ctrl, F=Shift. Right hand mirrored: J=Shift,
K=Ctrl, L=Alt, ;=GUI.

### Tap behavior (no false mods)
- [ ] Type a paragraph at normal speed — no stuck modifiers, no wrong characters
- [ ] Type fast same-hand rolls: `as`, `sa`, `df`, `fd`, `jk`, `kj`, `l;`
- [ ] Type common words containing home row keys: `the`, `and`, `said`, `dad`, `ask`, `flask`
- [ ] Type rapid double-letter: `aa`, `ss`, `dd`, `ff` — should produce letters, not mods
- [ ] Hold a key for auto-repeat (e.g. hold `a` for cursor purposes if applicable) — note: with `QUICK_TAP_TERM 0` this won't auto-repeat the letter; if you need it, raise the value

### Hold behavior (mods fire)
- [ ] Hold `D` + tap `C` → Ctrl+C (copy in most apps)
- [ ] Hold `D` + tap `V` → Ctrl+V (paste)
- [ ] Hold `D` + tap `Z` → Ctrl+Z (undo)
- [ ] Hold `K` + tap `C` → Ctrl+C from right hand
- [ ] Hold `F` + tap a letter → capital letter (Shift)
- [ ] Hold `J` + tap a letter → capital letter
- [ ] Hold `S` + tap `Tab` → Alt+Tab (window switch)
- [ ] Hold `A` + tap `Space` → GUI+Space (Spotlight on Mac, etc.)
- [ ] Same-hand mod test: hold `F` + tap `R` → Shift+R = `R`. Should work but slower; if it doesn't fire, consider `CHORDAL_HOLD`

### Tuning signals to record
- [ ] How many false mods per ~5 min of typing? (target: 0–1)
- [ ] Do mods feel sluggish? (note delay perception)
- [ ] Any key you want to drop the mod from?

## Word/line navigation (RAISE layer)

RAISE is the right thumb. Hold RAISE then test:

### macOS
- [ ] `RAISE + PRVWD` (right-hand pos for previous word) → jumps one word left (Alt+Left)
- [ ] `RAISE + NXTWD` → jumps one word right (Alt+Right)
- [ ] `RAISE + LSTRT` → jumps to line start (Cmd+Left)
- [ ] `RAISE + LEND` → jumps to line end (Cmd+Right)
- [ ] `RAISE + DLINE` → deletes word backward (Ctrl+Backspace)

### Linux
- [ ] `RAISE + PRVWD` → previous word (Ctrl+Left)
- [ ] `RAISE + NXTWD` → next word (Ctrl+Right)
- [ ] `RAISE + LSTRT` → line start (Home)
- [ ] `RAISE + LEND` → line end (End)
- [ ] `RAISE + DLINE` → delete word backward (Ctrl+Backspace)

### Windows
- [ ] `RAISE + PRVWD` → previous word (Ctrl+Left)
- [ ] `RAISE + NXTWD` → next word (Ctrl+Right)
- [ ] `RAISE + LSTRT` → line start (Home)
- [ ] `RAISE + LEND` → line end (End)
- [ ] `RAISE + DLINE` → delete word backward (Ctrl+Backspace)

## Gaming layer

- [ ] From base: hold LOWER+RAISE (enters ADJUST), tap the gaming toggle key
      (top row, position where Colemak used to be — `KC_E` slot)
- [ ] OLED shows `Game`
- [ ] Letters type as plain QWERTY (no HRM lag, no false mods)
- [ ] WASD work as raw keys for movement
- [ ] Spacebar works instantly with no tap-vs-hold delay
- [ ] LShift/LCtrl on bottom-row positions register as plain modifiers
- [ ] Toggle off (same key) returns to QWERTY with HRM
- [ ] OLED returns to `Base`

## Caps Word (existing)

- [ ] Tap both Shifts together → Caps Word activates (next word in caps)
- [ ] Double-tap Shift → Caps Word activates
- [ ] Auto-deactivates after space/punctuation/timeout

## Encoders

### Left encoder
- [ ] Default: rotate → Alt+Tab forward / Shift+Alt+Tab backward
- [ ] With RAISE held: rotate → Alt+\` window cycle (same-app windows)

### Right encoder
- [ ] Default: rotate → mouse wheel up/down
- [ ] With LOWER held: rotate → mouse wheel left/right

## Lower layer

- [ ] Numbers row 1–0 work
- [ ] Symbols row (`!@#$%^&*()`) works
- [ ] Brackets `{}[]`, pipe `|`, backslash `\` all work
- [ ] F1–F12 accessible

## Raise layer (other keys)

- [ ] Insert / PrtScr / Menu work (top row)
- [ ] Page Up / Page Down work
- [ ] Arrow keys (HJKL positions) work
- [ ] Caps Lock toggles

## Adjust layer

- [ ] QK_BOOT puts board into bootloader (top-left key)
- [ ] Mouse keys (movement + buttons + wheel) work
- [ ] Media keys (prev/play/next, vol up/down/mute) work
- [ ] KC_QWERTY sets QWERTY as persistent default

## Issues observed

(Use this section to note anything weird so we can address it.)

-
-
-
