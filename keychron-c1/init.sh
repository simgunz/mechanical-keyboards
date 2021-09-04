#!/usr/bin/env bash 
echo "Get sonix firmware..."
[[ ! -d qmk_firmware ]] && git clone --recurse-submodules -j8 https://github.com/SonixQMK/qmk_firmware.git

echo "Link custom directories..."
# link the keymap folder
ln -sfr $(pwd)/keymaps/simgunz qmk_firmware/keyboards/keychron/c1/keymaps/

# link the build script
ln -sfr $(pwd)/bin/build_c1_default.py qmk_firmware/bin/
ln -sfr $(pwd)/bin/build_c1_simgunz.py qmk_firmware/bin/

echo "Setting up build environment..."
sudo systemctl start docker
docker pull jath03/sonix_base_container
# first time
docker run --name sonix-qmk --interactive --tty -v "$(pwd)/keychron-c1/qmk_firmware/:/qmk" jath03/sonix_base_container
