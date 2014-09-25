#include "LedDriver.h"

static uint16_t * ledsAddress;

void LedDriver_Create(uint16_t * address) {
  ledsAddress = address;
  *ledsAddress = 0;
}

void LedDriver_TurnOn(uint8_t led) {
  *ledsAddress = led;
}
