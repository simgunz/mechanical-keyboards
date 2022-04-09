#!/usr/bin/env bash 
QMK_FIRMWARE_REF=3f94c63

echo "Get sonix firmware..."
[[ -d qmk_firmware ]] || git clone https://github.com/SonixQMK/qmk_firmware.git
(
  cd qmk_firmware
  git checkout ${QMK_FIRMWARE_REF}
  git submodule update --init --recursive --jobs 4
)
