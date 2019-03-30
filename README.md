# jhc-blackpill
led blink example for stm32f103 blackpill using haskell(jhc)

## Dependence

- jhc-libopencm3(https://github.com/1inguini/jhc-libopencm3)

## Build
first do `git submodule update --init --recursive --progress`

then `make -C Lib/libopencm3`

at last build with `stack ./Lib/Build.hs` at the root of this repo
