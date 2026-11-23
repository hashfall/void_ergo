// VOID Ergo S — Raspberry Pi Pico (RP2040)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/*
 * The split link is configured in keyboard.json (split.serial): RP2040 PIO
 * driver, half-duplex, single wire on GP0. The PIO implementation enables an
 * internal pull-up, so no external resistor is needed.
 */

/*
 * Double-tap RUN to enter the UF2 bootloader. GP25 is the on-board LED and
 * blinks while the bootloader waits for a flash.
 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
