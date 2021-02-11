# QMK setup

this repo contains

-   my keyboard firmwares
-   my keymaps
-   notes about QMK setup and config

---

## QMK Install

follow qmk tuto: https://beta.docs.qmk.fm/tutorial/newbs_getting_started

-   install qmk_toolbox
    -   https://github.com/qmk/qmk_toolbox
-   install qmk msys:
    -   https://beta.docs.qmk.fm/tutorial/newbs_getting_started#windows
    -   https://msys.qmk.fm/
    -   https://github.com/qmk/qmk_distro_msys/releases/tag/1.0.1

open `QMK MSYS` terminal directly to compile QMK easilly

## QMK setup

```
[rvion@DESKTOP-PIBCRS0 ~]$ qmk setup
Ψ Found qmk_firmware at C:/Users/rvion/qmk_firmware.
Ψ QMK Doctor is checking your environment.
Ψ Detected Windows.
Ψ QMK home: C:/Users/rvion/qmk_firmware
Ψ All dependencies are installed.
Ψ Found arm-none-eabi-gcc version 8.4.0
Ψ Found avr-gcc version 8.4.0
Ψ Found avrdude version 6.3
Ψ Found dfu-util version 0.10
Ψ Found dfu-programmer version 0.7.2
Ψ Submodules are up to date.
Ψ QMK is ready to go
```

---

# Bootstrap firmware code

from scratch:

1. edit layout on http://www.keyboard-layout-editor.com/#/
2. copy the data in "raw data" tab
3. paste it on https://kbfirmware.com/

from backup json file

1. open `dactylteensy2.json`
2. copy `firmware/dactylteensy_1.json` on https://kbfirmware.com/
3. tweak whatever you awnt
4. download zip

---

then extract / copy keyboard folder into `~/qmk_firmware/keyboards`

qmk use one folder per keyboard.
After extraction, you can check that your folder is listed via qmk list-keyboards:

```
qmk list-keyboards
qmk list-keyboards | grep coumba
coumbayatyl
```

✅ compile `default` layout

```shell
qmk compile -kb coumbayatyl -km default
make -j 1 coumbayatyl:default
```

✅ create new `rv1` layout

```shell
qmk new-keymap
Keyboard Name: coumbayatyl
Keymap Name: rv1
Ψ rv1 keymap directory created in: C:/Users/rvion/qmk_firmware/keyboards/coumbayatyl/keymaps/rv1
```

✅ compile `rv1` layout

```shell
qmk compile -kb coumbayatyl -km rv1
make -j 1 coumbayatyl:rv1
```

---

## quick reload ?

Didn't manage to make it work yet

I should investigate the `RESET` key code with teensy

ref discord:

```
Coumbaya: apparement c'est supporté
pro-micro en général c'est les classiques utilisés partout, des clones de sparkfun
elite-c c'est en usb-c et t'as des pins en plus
```

---

## Keymap.c notes

qmk repo is full of user configs
easy to get some inspiration.
doc is quite good despide steep entry

-   `LT` = layer tap
-   `MT` = mod tap

---

# VSCode setup for QMK

in addition to being present in this repo; I should also add config below to `~/qmk_firmware/.vscode/settings.json` :

```json
    "terminal.integrated.shell.windows": "C:\\Program Files\\QMK_MSYS\\usr\\bin\\bash.exe",
    "terminal.integrated.env.windows": {
        "MSYSTEM": "MINGW64",
        "CHERE_INVOKING": "1"
    },
    "terminal.integrated.shellArgs.windows": ["--login"],
    "terminal.integrated.cursorStyle": "line",
    "[c]": {
        "editor.formatOnSave": false
    },
```
