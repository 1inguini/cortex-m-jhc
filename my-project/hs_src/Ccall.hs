module Ccall where

import           Data.Word


foreign import ccall "mylib.h gpio_setup" gpio_setup :: IO ()
foreign import ccall "mylib.h wait" wait :: Word -> IO ()
foreign import ccall "mylib.h gpioB" gpioB :: IO Word32
foreign import ccall "mylib.h gpio12" gpio12 :: IO Word16
foreign import ccall "libopencm3/stm32/gpio.h gpio_set" gpio_set :: Word32 -> Word16 -> IO ()
foreign import ccall "libopencm3/stm32/gpio.h gpio_clear" gpio_clear :: Word32 -> Word16 -> IO ()

type Port = Word32
type Pin = Word16
