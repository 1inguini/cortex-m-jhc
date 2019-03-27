module Main where

import           Data.Word

foreign import ccall "mylib.h gpio_setup" gpio_setup :: IO ()
foreign import ccall "mylib.h led_toggle" led_toggle :: IO ()
foreign import ccall "mylib.h wait" wait :: Word -> IO ()
foreign import ccall "mylib.h led_on" led_on :: IO ()
foreign import ccall "mylib.h led_off" led_off :: IO ()


-- foreign import ccall "mylib.h gpio_set" c_gpio_set :: Int -> Int -> IO ()
-- foreign import ccall "mylib.h gpio_clear" c_gpio_clear :: Int -> Int -> IO ()
-- foreign import ccall "mylib.h gpioB" c_GPIOB :: IO Int
-- foreign import ccall "mylib.h gpio12" c_GPIO12:: IO Int



loop :: IO()
loop = do
  -- gpiob <- c_GPIOB
  -- gpio12 <- c_GPIO12
  -- wait
  -- led_toggle
  -- wait
  -- led_toggle
  wait 100000
  led_on
  -- c_gpio_clear gpiob gpio12
  wait 100000
  led_off

  loop

main :: IO ()
main = do
  gpio_setup
  loop
  -- led_off
  -- led_on
