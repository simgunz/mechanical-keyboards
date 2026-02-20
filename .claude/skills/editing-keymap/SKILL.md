---
name: editing-keymap
description: Edits QMK keymap.c layout files with proper alignment and validation. Use when the user asks to modify keyboard layers, change keycodes, add custom keys, or edit the keyboard layout. Requires Opus model for precision.
model: opus
allowed-tools: Read, Edit, Bash, Grep
---

# QMK Keymap Editing Skill

This skill provides a structured process for editing the QMK keymap.c file to prevent common mistakes with the visually-aligned matrix layout.

## Layout Location

**Path**: `/media/data/linux/mechanical-keyboards/keychron-c1/keymaps/simgunz/keymap.c`

## Matrix Structure

The keyboard uses a **6 rows × 17 columns** matrix:

| Row | Physical Keys |
|-----|---------------|
| 0   | F-row (ESC, F1-F12, PrtSc, etc.) |
| 1   | Number row (`, 1-0, -, =, Backspace, Ins, Home, PgUp) |
| 2   | QWERTY row (Tab, Q-], \, Del, End, PgDn) |
| 3   | Home row (Caps, A-', Enter) |
| 4   | Bottom alpha (Shift, Z-/, RShift, Up) |
| 5   | Modifier row (Ctrl, Win, Alt, Space, etc., arrows) |

## Layers

- `WIN_BASE` (0) - Base Windows layout
- `WIN_FN` (1) - Function layer (MO key)
- `WIN_CAPS` (2) - Navigation layer (Caps hold)
- `WIN_NUMS` (3) - Numpad layer (Tab hold)
- `MAC_BASE` (4) - Mac base (unused)
- `MAC_FN` (5) - Mac function (unused)

## CRITICAL: 5-Step Editing Protocol

### Step 1: Read the File First
ALWAYS read keymap.c before any edit:
```
Read /media/data/linux/mechanical-keyboards/keychron-c1/keymaps/simgunz/keymap.c
```

### Step 2: Identify Target Position
Determine:
1. Which **layer** to modify
2. Which **row** (0-5)
3. Which **column** (0-16)

Use the column header comment in the file:
```c
/*  0          1          2          3          4          5          6          7          8          9          10         11         12         13         14         15         16     */
```

### Step 3: Extract Full Row Context
When editing, include the ENTIRE row in your `old_string`. Never edit partial rows.

### Step 4: Preserve Alignment
Each cell is ~10 characters (keycode + comma + spaces):

| Keycode Length | Padding Example |
|----------------|-----------------|
| 6 chars | `KC_ESC,   ` (3 spaces) |
| 5 chars | `KC_F1,    ` (4 spaces) |
| 7 chars | `KC_MPRV,  ` (2 spaces) |
| 7 chars | `_______,  ` (2 spaces) |

### Step 5: Validate After Edit
After every edit, verify:
1. Row has exactly 17 entries
2. Alignment matches column headers
3. Adjacent keys unchanged
4. Build succeeds: `make build`

## Column Reference by Row

### Row 0 (F-row)
```
Col: 0=ESC  1=F1   2=F2   3=F3   4=F4   5=F5   6=F6   7=F7   8=F8   9=F9   10=F10  11=F11  12=F12  13=gap  14=PrtSc 15=MicMute 16=RGB
```

### Row 1 (Numbers)
```
Col: 0=`    1=1    2=2    3=3    4=4    5=5    6=6    7=7    8=8    9=9    10=0    11=-    12==    13=Bksp 14=Ins  15=Home  16=PgUp
```

### Row 2 (QWERTY)
```
Col: 0=Tab  1=Q    2=W    3=E    4=R    5=T    6=Y    7=U    8=I    9=O    10=P    11=[    12=]    13=\    14=Del  15=End   16=PgDn
```

### Row 3 (Home)
```
Col: 0=Caps 1=A    2=S    3=D    4=F    5=G    6=H    7=J    8=K    9=L    10=;    11='    12=gap  13=Enter 14-16=gaps
```

### Row 4 (Bottom alpha)
```
Col: 0=LShift 1=gap 2=Z   3=X    4=C    5=V    6=B    7=N    8=M    9=,    10=.    11=/    12=gap  13=RShift 14=gap 15=Up  16=gap
```

### Row 5 (Modifiers)
```
Col: 0=LCtrl 1=LWin 2=LAlt 3-5=gaps 6=Space 7-9=gaps 10=RAlt 11=RWin 12=Fn 13=RCtrl 14=Left 15=Down 16=Right
```

## Special Values

- `_______` - Transparent (inherit from lower layer)
- `KC_NO` - Position disabled
- Custom keycodes are defined in the `enum` at top of file

## Defining Custom Key Aliases

Use `#define` for modifier combinations and key aliases (same pattern as `KC_TASK`, `KC_SNIP`, etc.):
```c
#define KC_DICT LCTL(LSFT(LALT(KC_SPC))) // description
```

Use `enum` + `process_record_user` only when custom logic is needed (e.g. `SEND_STRING`, conditional behavior, timers). Do NOT use enum for simple modifier combos.

## Common Mistakes to Avoid

1. **Wrong column** - Always count from 0, use column header as guide
2. **Broken alignment** - Preserve exact spacing after keycode
3. **Missing comma** - Every entry except last needs comma
4. **Partial keycode** - Always replace complete keycode name
5. **Wrong layer** - Double-check layer name before editing
6. **`replace_all` corrupting `#define`** - If the same pattern appears in both a `#define` and the keymap body, `replace_all` will break the `#define`. Replace each occurrence individually instead.

## Build Verification

After any edit, run:
```bash
make build
```

This compiles the firmware and catches syntax errors.
