# Keychron C1 Makefile
.DEFAULT_GOAL := help

# Variables
KEYMAP=simgunz
QMK_DIR=qmk_firmware
KEYBOARD=keychron/c1/rgb
FIRMWARE_BIN=$(QMK_DIR)/keychron_c1_rgb_$(KEYMAP).bin
FLASHER=./sonixflasher
VIDPID=0c45/7040

.PHONY: setup build flash clean help

setup:  ## Run environment setup script
	./init.sh

build:  ## Build the firmware
	cd $(QMK_DIR) && nix-shell --run 'qmk config user.keyboard=$(KEYBOARD) && qmk config user.keymap=$(KEYMAP) && qmk compile'

flash:  ## Flash the firmware to the keyboard
	@if [ ! -f $(FIRMWARE_BIN) ]; then \
		echo "Firmware binary not found: $(FIRMWARE_BIN). Run 'make build' first."; \
		exit 1; \
	fi
	$(FLASHER) --vidpid $(VIDPID) --file $(FIRMWARE_BIN) --offset 0x00

clean:  ## Remove built firmware binary
	rm -f $(QMK_DIR)/keychron_c1_rgb_$(KEYMAP).bin

help:  ## Show this help
	@echo "Specify a command. The choices are:"
	@grep -E '^[0-9a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[0;36m%-12s\033[m %s\n", $$1, $$2}'