## Introduction
This is my keymap for [cantor keyboard](https://github.com/diepala/cantor). It was heavily inspired by [crkbd/markstos mapping](https://github.com/markstos/qmk_firmware/blob/markstos/keyboards/crkbd/keymaps/markstos/README.md).
**Some mappings may not make sense if you are not using pt-BR ABNT2 keyboard layout.**

## Prerequisites
Make sure that you have QMK CLI installed and properly working. You can try running `qmk compile -kb cantor -km default` to test the default cantor mapping compilation.

## Installation
Find where is your `qmk_firmware` folder, it'll be considered `~/qmk_firmware` because its the default location for Linux.
```bash
git clone https://github.com/jpcairesf/keymap.git
cp -r ./keymap/cantor/jpcairesf ~/qmk_firmware/keyboards/cantor/keymaps/
```
Now compile the keymap running the command below.
```bash
qmk compile -kb cantor -km jpcairesf
```

## Changing the master hand
This keymap configuration sets the left hand as the master, this means that the USB-C cable must be connected in the left piece. 
To change the master hand to be the right, open the file `config.h` in the keymap folder and make the following changes.
```c
#define MASTER_LEFT
// #define MASTER_RIGHT
```
Change it to
```c
// #define MASTER_LEFT
#define MASTER_RIGHT
```
