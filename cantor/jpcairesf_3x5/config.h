/*
 * QMK config.h file
 */

#pragma once

// -- Split Keyboard Configuration --
// By default, QMK assumes the left hand is the master.
// If you want the right hand to be master, comment out the line below.
#define MASTER_LEFT

// -- Tapping and Combo Configuration --

// How long the firmware waits to decide if a key is a tap or a hold (in ms).
// This is important for keys like LALT_T(KC_Z).
// A lower value makes hold-actions trigger faster; a higher value makes tapping easier.
#define TAPPING_TERM 200

// How long to wait for the next key in a combo sequence (in ms).
#define COMBO_TERM 50

// Helps prevent modifiers (like Shift or Ctrl) from getting stuck.
// Highly recommended for most keymaps.
#define PREVENT_STUCK_MODIFIERS

// -- Debounce Configuration --
// Reduces key chatter (unintended double presses) by waiting a small
// amount of time before registering a key press. 5ms is a common, safe value.
#define DEBOUNCE 5

// https://www.reddit.com/r/ErgoMechKeyboards/comments/1en7jp5/comment/lh44jb3
#define SPLIT_WATCHDOG_ENABLE
