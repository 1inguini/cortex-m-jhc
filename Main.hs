module Main where

import           Lib.Ccall as C

blink :: Port -> Pin -> IO ()
blink port pin = do
  wait 100000
  C.gpioClear port pin
  wait 100000
  C.gpioSet port pin

  blink port pin

onOff :: Port -> Pin -> Port -> Pin -> IO ()
onOff inPort inPin outPort outPin = do
  state <- C.gpioGet inPort inPin
  if state == 0
    then C.gpioClear outPort outPin
    else C.gpioSet   outPort outPin

main :: IO ()
main = do
  C.rccPeriphClockEnableGpioA
  C.rccPeriphClockEnableGpioB
  C.rccPeriphClockEnableUsart2

  gpioB  <- C.gpioB
  gpio12 <- C.gpio12

  gpioA  <- C.gpioA
  gpio0  <- C.gpio0

  gpioModeOutput2Mhz     <- C.gpioModeOutput2Mhz
  gpioCnfOutputPushpull  <- C.gpioCnfOutputPushpull

  gpioModeInput          <- C.gpioModeInput
  gpioCnfInputPullUpdown <- C.gpioCnfInputPullUpdown

  C.gpioSetMode
    gpioB
    gpioModeOutput2Mhz
    gpioCnfOutputPushpull
    gpio12

  C.gpioSetMode
    gpioA
    gpioModeInput
    gpioCnfInputPullUpdown
    gpio0

  blink gpioB gpio12

  -- onOff gpioA gpio0 gpioB gpio12
