# Keychron C1

vid:pid `05ac:024f`

vid:pid (bootloader) `0c45:7040`

Chip `SN32F248B`

## Build

```bash
# setup the build environment
./init.sh

# build the keymap
docker compose up
```

The resulting bin is `qmk_firmware/keychron_c1_simgunz.bin`

## Flash

1. Connect the keyboard DIRECTLY to the notebook using a HIGH QUALITY usb cable
1. I repeat...connect the keyboard directly, not through a hub that can shutdown in case of power outage
2. Put the keyboard in bootloader mode with `Fn + Esc`
3. ~~Open [sonix-flasher](https://github.com/SonixQMK/sonix-flasher/tags) in windows~~
4. Run sonix-flasher with `./run.sh`
5. Check that the revealed keyboard is in bootloader mode `0c45:7040`
6. Select `SN32F24X` under 'Device' and select `0x00` as the qmk offset
7. Click 'Flash QMK...' and find the compiled firmware

## Openrgb

```bash
# check that the two branches are aligned
git diff HEAD..origin/sn32_openrgb -- keyboards/keychron/c1/
git checkout sn32_openrgb
```

## Notes

- The versions of both `qmk_firmware` and `sonix-flasher` are fixed in the `init.sh` script, change the versions there to update to a newer version
- [2022-04-09] As for today the main branch to use seems to be `sn32_master`. The `sn32_stable` contains the latest changes to the `C1` related files.
