#!/usr/bin/env bash 
echo "Get sonix firmware..."
[[ ! -d qmk_firmware ]] && git clone --recurse-submodules -j8 https://github.com/SonixQMK/qmk_firmware.git

echo "Setting up build environment..."
sudo systemctl start docker
docker pull jath03/sonix_base_container
# first time
docker run --name sonix-qmk --interactive --tty -v "$(pwd)/keychron-c1/qmk_firmware/:/qmk" jath03/sonix_base_container
