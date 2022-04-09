# Mechanical keyboards

Linux remaps some XF86 keys to F keys (e.g. XF86AudioMicMute is mapped to F20).
To get the correct F keycode do the following:

```bash
# get the xorg keycode for XF86AudioMicMute (198)
xmodmap -pke | grep XF86AudioMicMute
# convert the xorg keycode to a hid keycode (111, '0x6f')
python scripts/xorghidkeycodesconverter.py to_hid 198
# get the 6th block of keys from the qmk keycode file
grep -A 15 0x60 qmk_firmware/tmk_core/common/keycode.c
# 'f' = 16 lines to get the correct key name
```

## Troubleshoot

### The keyboard does not work after boot

https://github.com/SonixQMK/qmk_firmware/issues/78

## Supported keyboards

### Redragon

[List of redragon keyboards that support sonix qmk](https://docs.google.com/spreadsheets/d/1uBWiHgeF1GwCICTLEvo8Vl19wy8l_bP2lSloxkSTgeg/edit#gid=0)

### Keychron

- Keychron C1 RGB
