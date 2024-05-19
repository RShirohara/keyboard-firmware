# `keyboard-firmware`

Self-made keyboards keymaps and firmwares.

## Development

### Requirements

- `git`
- `qmk`

### How to build

#### 1. Setting up QMK Environment

Ref: <https://docs.qmk.fm/#/newbs_getting_started>

#### 2. Clone this repository and update submodules

```shell
make git-submodule
```

#### 3. Build firmwares and keymaps

##### for QMK

```shell
kb=<keyboard> km=<keymap> make qmk-compile
```
