Last long term test with qmk version: 0.13.38
current version: 0.15.1

## Manual Setup

1. Create symlink to this dir as `qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/claudio5x6`
2. Create symlink from `qmk.ini` in application dir. In MacOS, that's `~/Library/Application Support/qmk/qmk.ini`

## Upgrading Firmware version

1. `git pull` and then checkout to latest stable tag 
2. `make git-submodule` to update submodules
3. `qmk clean` to remove incompatible artifacts from build folder
4. `qmk doctor`
5. `qmk compile` (assumes setup is done)
6. Flash BOTH sides of keyboard separately (they don't need to be connected to each other)
