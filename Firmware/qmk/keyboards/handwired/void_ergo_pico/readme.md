# VOID Ergo S (Pico)

Port of the handwired VOID Ergo S to the Raspberry Pi Pico (RP2040).

* Keyboard Maintainer: [hashfall](https://github.com/hashfall)
* Hardware Supported: Raspberry Pi Pico (RP2040), 2 units (one per half)
* Hardware Availability: [raspberrypi.com](https://www.raspberrypi.com/products/raspberry-pi-pico/)

The matrix wiring is the same on both halves; the wiring table lives in
[WIRING.md](WIRING.md).

Make example for this keyboard (after setting up your build environment):

    make handwired/void_ergo_pico:default

Flashing example for this keyboard:

    make handwired/void_ergo_pico:default:flash

To enter the bootloader, either hold BOOTSEL while plugging the Pico in,
double-tap the RUN pin, or use a `QK_BOOT` keycode in your keymap. Then copy the
generated `.uf2` file to the `RPI-RP2` drive.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for
more information. Brand new to QMK? Start with the
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
