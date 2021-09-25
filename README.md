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

# Redragon

[List of redragon keyboards that support sonix qmk](https://docs.google.com/spreadsheets/d/1uBWiHgeF1GwCICTLEvo8Vl19wy8l_bP2lSloxkSTgeg/edit#gid=0)

# Keychron C1

vid:pid `05ac:024f`

vid:pid (bootloader) `0c45:7040`

Chip `SN32F248B`

## Build

```bash
# setup the build environment
./init.sh

# enter the docker build environment
./start_env.sh
```

Inside docker

```bash
cd /qmk/qmk_firmware
make keychron/c1:simgunz
```

To checkout specific pull requests

```bash
gh auth login  # only first time
gh pr checkout 39
```

## Flash

1. Connect the keyboard DIRECTLY to the notebook using a HIGH QUALITY usb cable
2. Put the keyboard in bootloader mode with `Fn + Esc`
3. Open [sonix-flasher](https://github.com/SonixQMK/sonix-flasher/tags) in windows
4. Check that the revealed keyboard is in bootloader mode `0c45:7040`
5. Select `SN32F24X` under 'Device' and select `0x00` as the qmk offset
6. Click 'Flash QMK...' and find the compiled firmware

## Openrgb

```bash
# check that the two branches are aligned
git diff HEAD..origin/sn32_openrgb -- keyboards/keychron/c1/
git checkout sn32_openrgb
```

