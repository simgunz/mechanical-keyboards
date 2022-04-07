#!/usr/bin/env bash 
echo "Get sonix firmware..."
[[ ! -d qmk_firmware ]] && git clone --recurse-submodules -j8 https://github.com/SonixQMK/qmk_firmware.git
