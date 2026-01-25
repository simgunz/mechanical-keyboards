# CLAUDE.md

QMK firmware configuration for Keychron C1 RGB keyboard.

## Layer Architecture

The keymap implements 6 layers:

1. **WIN_BASE** - Base Windows layout with layer triggers
2. **WIN_FN** - Function layer (system controls, RGB)
3. **WIN_CAPS** - Navigation layer (Caps Lock hold - F-keys, vim navigation, word ops)
4. **WIN_NUMS** - Numpad layer (TAB hold - numpad + VS Code test commands)
5. **MAC_BASE/MAC_FN** - Mac layouts (unused)

Key features:
- Layer-tap: `LT(WIN_NUMS, KC_TAB)`, `MO(WIN_CAPS)` on Caps Lock
- Combo: J+K → Escape 
- Tap dance: Right Shift (tap/double-tap for Shift/Ctrl+;)
- Custom keycodes for VS Code test commands

## Layout Location

**Path**: `/media/data/linux/mechanical-keyboards/keychron-c1/keymaps/simgunz/`

## Core Files

- **`keymap.c`** - Layer definitions, custom keycodes, process_record_user()
- **`config.h`** - Timing parameters and feature settings
- **`rules.mk`** - Feature flags (COMBO_ENABLE, MOUSEKEY_ENABLE, TAP_DANCE_ENABLE)

## Implementation Patterns

**Layer Structure**: 2D arrays mapping matrix positions to keycodes
- `_______` inherits from lower layers
- `KC_NO` disables key position

**Custom Features**:
- Enums: Custom keycodes from `SAFE_RANGE`
- `process_record_user()`: Handle custom behavior with `SEND_STRING()`
- VS Code commands: `SEND_STRING(SS_LCTL(";") "x")` pattern

**Current Settings**:
- `TAPPING_TERM 250` (layer-tap timing)
- `COMBO_TERM 250` (combo timing) 
- `COMBO_COUNT 1` (J+K combo)
- `RGB_MATRIX_STARTUP_MODE RGB_MATRIX_NONE` (RGB off by default)

## Build Command

```bash
make build
```

## Keycode Mapping

For XF86 keys:
```bash
# Get xorg keycode
xmodmap -pke | grep XF86AudioMicMute
# Convert to HID 
python scripts/xorghidkeycodesconverter.py to_hid 198
# Find QMK keycode
grep -A 15 0x60 qmk_firmware/tmk_core/common/keycode.c
```