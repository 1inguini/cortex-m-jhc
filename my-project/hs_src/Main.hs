module Main where

import           Foreign.C.Types
import           Foreign.Ptr
import           Foreign.Storable

foreign import ccall "mylib.h gpio_setup" gpio_setup :: IO ()
foreign import ccall "mylib.h led_toggle" led_toggle :: IO ()
foreign import ccall "mylib.h wait" wait :: IO ()
foreign import ccall "mylib.h led_on" led_on :: IO ()
foreign import ccall "mylib.h led_off" led_off :: IO ()
foreign import ccall "mylib.h rcc_periph_clock_enable" rcc_periph_clock_enable:: IO ()


loop :: IO()
loop = do
  -- wait
  -- led_toggle
  -- wait
  -- led_toggle
  wait
  led_on
  wait
  led_off

  loop

main :: IO ()
main = do
  gpio_setup
  loop
  -- led_off
  -- led_on
