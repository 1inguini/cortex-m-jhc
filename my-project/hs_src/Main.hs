module Main where

import           Data.Word

foreign import ccall "mylib.h gpio_setup" gpio_setup :: IO ()
foreign import ccall "mylib.h wait" wait :: Word -> IO ()
foreign import ccall "mylib.h gpioB" c_GPIOB :: IO Word32
foreign import ccall "mylib.h gpio12" c_GPIO12 :: IO Word16
foreign import ccall "libopencm3/stm32/gpio.h gpio_set" c_gpio_set :: Word32 -> Word16 -> IO ()
foreign import ccall "libopencm3/stm32/gpio.h gpio_clear" c_gpio_clear :: Word32 -> Word16 -> IO ()

type Port = Word32
type Pin = Word16

blink :: Port -> Pin ->IO()
blink port pin = do
  wait 100000
  c_gpio_clear port pin
  wait 100000
  c_gpio_set port pin

  blink port pin

main :: IO ()
main = do
  gpioB <- c_GPIOB
  gpio12 <- c_GPIO12
  gpio_setup
  blink gpioB gpio12
