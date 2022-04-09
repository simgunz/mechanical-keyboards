#!/usr/bin/env bash 
QMK_FIRMWARE_REF=3f94c63
SONIX_FLASHER_REF=v0.2.4

if [[ $1 = '--help' ]]; then
  echo "usage: init.sh [--flasher]"
  exit 0
fi

echo "Get sonix firmware..."
[[ -d qmk_firmware ]] || git clone https://github.com/SonixQMK/qmk_firmware.git
(
  cd qmk_firmware
  git checkout ${QMK_FIRMWARE_REF}
  git submodule update --init --recursive --jobs 4
)

if [[ $1 = '--flasher' ]]; then
  echo "Get sonix flasher..."
  [[ -d sonix-flasher ]] || git clone https://github.com/SonixQMK/sonix-flasher.git
  (
    cd sonix-flasher
    git checkout ${SONIX_FLASHER_REF}
  )
fi
