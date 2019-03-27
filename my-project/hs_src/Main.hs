module Main where

import           Ccall as C

blink :: Port -> Pin ->IO()
blink port pin = do
  wait 100000
  C.gpio_clear port pin
  wait 100000
  C.gpio_set port pin

  blink port pin

main :: IO ()
main = do
  gpioB <- C.gpioB
  gpio12 <- C.gpio12
  C.gpio_setup
  blink gpioB gpio12
