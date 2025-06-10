# Keychron C1

## Parameters

- **Normal mode VID:PID:** `05ac:024f`
- **Bootloader VID:PID:** `0c45:7040`
- **Chip:** `SN32F248B`
- **Variant:** RGB

## Build (for latest qmk_firmware at sn32_master_stable)

For the latest version of `qmk_firmware` at `sn32_master_stable`, Docker is no longer used. Instead, use `nix-shell` and the QMK CLI:

```bash
# Enter the Nix shell environment in the qmk_firmware directory
cd qmk_firmware
nix-shell

# Configure your keyboard and keymap (run once)
qmk config user.keyboard=keychron/c1/rgb
qmk config user.keymap=simgunz

# Compile the firmware
qmk compile
```

The resulting firmware binary will be copied as `keychron_c1_rgb_simgunz.bin` to the `qmk_firmware` folder.

## Flash

### SonixFlasherC (CLI)

1. Ensure `sonixflasher` is available (it will be pulled and built automatically by `init.sh`).
2. Connect the keyboard **directly** to your notebook using a high-quality USB cable (avoid hubs).
3. Put the keyboard in bootloader mode: press `Fn + Esc`.
4. Confirm the device appears as `0c45:7040` (bootloader mode) using `lsusb` or similar.
5. Flash the firmware with:
   ```bash
   ./sonixflasher --vidpid 0c45/7040 --file qmk_firmware/keychron_c1_rgb_simgunz.bin --offset 0x00
   ```
   - Adjust the path to the firmware binary if needed.
   - The `--offset 0x00` is required for QMK firmware.

### sonix-flasher (UI)

1. Connect the keyboard **directly** to your notebook using a high-quality USB cable (avoid hubs).
2. Enter bootloader mode: press `Fn + Esc` on the keyboard.
3. Run the sonix-flasher UI tool:
   ```bash
   ./run.sh
   ```
4. Confirm the keyboard appears as `0c45:7040` (bootloader mode).
5. In the UI:
   - Select `SN32F24X` under 'Device'.
   - Set QMK offset to `0x00`.
   - Click 'Flash QMK...' and select the compiled firmware (`qmk_firmware/keychron_c1_simgunz.bin`).

## Openrgb (unverified as for 2025-05-25)

```bash
# check that the two branches are aligned
git diff HEAD..origin/sn32_openrgb -- keyboards/keychron/c1/
git checkout sn32_openrgb
```

## Changelog

- [2022-04-09] The main branch to use was `sn32_master`. The `sn32_stable` branch contained the latest changes to the `C1` related files.
- [2025-06-04] The commit of `qmk_firmware` used for versions 0.2.6 and below of this repository was `3f94c632`.
- [2024-06-10]
  - The commit of `qmk_firmware` at `sn32_master_stable` is `41aa96b0`.
  - `sn32_master_stable` was last updated in 2022; this is the correct branch for the Keychron C1.
  - Keychron C1 keyboards folder now contains three types: plain, white, rgb.

## Notes

- The versions of both `qmk_firmware` and `sonix-flasher` are fixed in the `init.sh` script. Change the versions there to update to a newer version.
- **Keymap directory structure:**
  - For older QMK versions (commit `3f94c632` and repo version <=0.2.6), your keymap should be linked to:
    `qmk_firmware/keyboards/keychron/c1/keymaps/simgunz`
  - For newer QMK versions (`sn32_master_stable`), your keymap should be linked to:
    `qmk_firmware/keyboards/keychron/c1/rgb/keymaps/simgunz`

## Troubleshoot

### Failed to build `hidapi`

- Edit `requirements.txt` in the `sonix-flasher` directory and **remove the version pin** for `hidapi`.
- Re-run the build process.

---

## Legacy instructions (for qmk_firmware commit 3f94c632, repo version <=0.2.6)

These instructions apply to repository versions up to **0.2.6**, which use `qmk_firmware` at commit `3f94c632`.

- Running `./init.sh` will:
  - Clone `qmk_firmware` at commit `3f94c632` and initialize its submodules.
  - If run as `./init.sh --flasher`, it will also clone the `sonix-flasher` UI tool.

```bash
# setup the build environment
./init.sh

# (optional) also fetch sonix-flasher UI tool
./init.sh --flasher

# build the keymap
docker compose up
```

The resulting firmware binary will be located at `qmk_firmware/keychron_c1_simgunz.bin`.
