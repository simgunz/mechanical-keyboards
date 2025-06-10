#!/usr/bin/env bash
QMK_FIRMWARE_REF=sn32_master_stable
SONIX_FLASHERC_REF=2.0.8

if [[ $1 = '--help' ]]; then
  echo "usage: init.sh"
  exit 0
fi

echo "Get sonix firmware..."
[[ -d qmk_firmware ]] || git clone https://github.com/SonixQMK/qmk_firmware.git
(
  cd qmk_firmware || exit 1
  git checkout "${QMK_FIRMWARE_REF}"
  git submodule update --init --recursive --jobs 4
)

echo "Get and build SonixFlasherC (CLI)..."
[[ -d flasher ]] || git clone https://github.com/SonixQMK/SonixFlasherC.git flasher
(
  cd flasher || exit 1
  git checkout "${SONIX_FLASHERC_REF}"
  make sonixflasher
)
ln -sf "$(pwd)/flasher/sonixflasher" ./sonixflasher

echo "Link my keymap to qmk_firmware directory..."
ln -sfn "$(pwd)/keymaps/simgunz" qmk_firmware/keyboards/keychron/c1/rgb/keymaps/simgunz
