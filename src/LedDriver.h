#include <stdint.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(uint8_t led);
void LedDriver_TurnOff(uint8_t led);
void LedDriver_TurnOnAll(void);
void LedDriver_TurnOffAll(void);
