#include "unity_fixture.h"
#include <stdint.h>

#include "LedDriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver) {

}

TEST_TEAR_DOWN(LedDriver) {

}

TEST(LedDriver, LedDriverCreate) {
  uint16_t led = 0xffff;
  LedDriver_Create(&led);
  TEST_ASSERT_EQUAL_HEX16(0,led);
}

TEST(LedDriver, LedDriverTurnOnOneLed) {
  uint16_t led = 0xffff;
  LedDriver_Create(&led);
  LedDriver_TurnOn(1);
  TEST_ASSERT_EQUAL_HEX16(1,led);
}
