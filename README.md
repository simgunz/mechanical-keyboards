# Mechanical keyboards

# Redragon

[https://docs.google.com/spreadsheets/d/1uBWiHgeF1GwCICTLEvo8Vl19wy8l_bP2lSloxkSTgeg/edit#gid=0](https://docs.google.com/spreadsheets/d/1uBWiHgeF1GwCICTLEvo8Vl19wy8l_bP2lSloxkSTgeg/edit#gid=0)

# Keychron C1

vid:pid `05ac:024f`

vid:pid (bootloader) `0c45:7040`

Chip `SN32F248B`

## Build

```bash
cd /media/dataHD/linux/mechanical-keyboards/keychron-c1
git clone --recurse-submodules -j8 https://github.com/SonixQMK/qmk_firmware.git
cd qmk_firmware
gh auth login  # only first time
gh pr checkout 39
```

```bash
sc-start docker
docker pull jath03/sonix_base_container
# first time
docker run --name sonix-qmk --interactive --tty -v /media/dataHD/linux/mechanical-keyboards/keychron-c1/qmk_firmware/:/qmk jath03/sonix_base_container
# next times
docker container start -i sonix-qmk
```

Link keymaps and scripts

```bash
# link the keymap folder
mkdir -p keymaps/simgunz
ln -sfr $(pwd)/keymaps/simgunz qmk_firmware/keyboards/keychron/c1/keymaps/simgunz

# link the build script
ln -sfr $(pwd)/bin/build_c1_default.py qmk_firmware/bin/
ln -sfr $(pwd)/bin/build_c1_simgunz.py qmk_firmware/bin/

```

For openrgb

```bash
# check that the two branches are aligned
git diff HEAD..origin/sn32_openrgb -- keyboards/keychron/c1/
git checkout sn32_openrgb
```

Inside docker

```bash
cd /qmk/
python3 bin/build_c1_default.py

```

