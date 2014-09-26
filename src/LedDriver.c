#include "LedDriver.h"

static uint16_t * ledsAddress;
static uint16_t ledsImage;

static void updateHardware() {
  *ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t * address) {
  ledsAddress = address;
  ledsImage = 0;
  updateHardware();
}

void LedDriver_TurnOn(uint8_t led) {
  ledsImage |= 1<<(led-1);
  updateHardware();
}

void LedDriver_TurnOff(uint8_t led) {
  ledsImage &= ~(1<<(led-1));
  updateHardware();
}

void LedDriver_TurnOnAll(void) {
  ledsImage = 0xffff;
  updateHardware();
}

void LedDriver_TurnOffAll(void) {
  ledsImage = 0;
  updateHardware();
}
