import argparse
import sys

# Source of the below lookup table:
# https://elixir.bootlin.com/linux/latest/source/drivers/hid/hid-input.c#L27
hid_keyboard = [ 0,  0,  0,  0, 30, 48, 46, 32, 18, 33, 34, 35, 23, 36, 37, 38,
        50, 49, 24, 25, 16, 19, 31, 20, 22, 47, 17, 45, 21, 44,  2,  3,
        4,  5,  6,  7,  8,  9, 10, 11, 28,  1, 14, 15, 57, 12, 13, 26,
        27, 43, 43, 39, 40, 41, 51, 52, 53, 58, 59, 60, 61, 62, 63, 64,
        65, 66, 67, 68, 87, 88, 99, 70,119,110,102,104,111,107,109,106,
        105,108,103, 69, 98, 55, 74, 78, 96, 79, 80, 81, 75, 76, 77, 71,
        72, 73, 82, 83, 86,127,116,117,183,184,185,186,187,188,189,190,
        191,192,193,194,134,138,130,132,128,129,131,137,133,135,136,113,
        115,114,None,None,None,121,None, 89, 93,124, 92, 94, 95,None,None,None,
        122,123, 90, 91, 85,None,None,None,None,None,None,None,111,None,None,None,
        None,None,None,None,None,None,None,None,None,None,None,None,None,None,None,None,
        None,None,None,None,None,None,179,180,None,None,None,None,None,None,None,None,
        None,None,None,None,None,None,None,None,None,None,None,None,None,None,None,None,
        None,None,None,None,None,None,None,None,111,None,None,None,None,None,None,None,
        29, 42, 56,125, 97, 54,100,126,164,166,165,163,161,115,114,113,
        150,158,159,128,136,177,178,176,142,152,173,140,None,None,None,None
        ];


# The evdev driver in X11 remaps 
# Linux input keycodes by adding 8 to them; 
# libinput does the same thing.
def HID_to_Xorg(keycode):
    assert type(keycode) == int
    hid_keycode = hid_keyboard[keycode]
    if hid_keycode is None:
        return None
    else:
        return hid_keycode + 8


def Xorg_to_HID(keycode):
    assert type(keycode) == int
    hid_keycode = hid_keyboard.index(keycode - 8)
    return hid_keycode, hex(hid_keycode)


parser = argparse.ArgumentParser()
# parser.add_argument('--help', action='store_true')
subparsers = parser.add_subparsers()
hidtoxorg = subparsers.add_parser('to_xorg')
hidtoxorg.add_argument('code', help='HID keycode used in QMK. It is the value of the '
        'elements in the enum hid_keyboard_keypad_usage in '
        'qmk_firmware/tmk_core/common/keycode.h.', type=int)
hidtoxorg.set_defaults(func=HID_to_Xorg)

xorgtohid = subparsers.add_parser('to_hid')
xorgtohid.add_argument('code', help='Xorg keycode as displayed by xmodmap -pke', type=int)
xorgtohid.set_defaults(func=Xorg_to_HID)



args = parser.parse_args()

print(args.func(args.code))
