#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

int main() {

  const uint led_pin = 25;

  // Initialize LED pin
  gpio_init(led_pin);
  gpio_set_dir(led_pin, GPIO_OUT);

  // Initialize chosen serial port
  stdio_init_all();

  timer_hw->dbgpause = 0; // need this due to bug in SDK2.1.0 (see https://github.com/raspberrypi/pico-sdk/issues/2132)

  // Loop forever
  while (true) {

    // Blink LED
    gpio_put(led_pin, false);
    sleep_ms(100);
    gpio_put(led_pin, true);

    // get a character over serial
    printf("Enter a character... ");
    char getchar_return = getchar_timeout_us(1000000);

    // output that character
    printf("\tYou entered: %c\n", getchar_return);
  }
}