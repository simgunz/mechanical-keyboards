# Mechanical keyboards

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

# Openrgb

```bash
# check that the two branches are aligned
git diff HEAD..origin/sn32_openrgb -- keyboards/keychron/c1/
git checkout sn32_openrgb
```

