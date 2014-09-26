#include "unity_fixture.h"
#include <stdint.h>

#include "LedDriver.h"

TEST_GROUP(LedDriver);

static uint16_t virtualLeds;

TEST_SETUP(LedDriver) {
  virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver) {

}

TEST(LedDriver, Create) {
  TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver, TurnOnLedOne) {
  LedDriver_TurnOn(1);
  TEST_ASSERT_EQUAL_HEX16(1,virtualLeds);
}

TEST(LedDriver, TurnOnLedThree) {
  LedDriver_TurnOn(4);
  TEST_ASSERT_EQUAL_HEX16(0x0008,virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds) {
  LedDriver_TurnOn(4);
  LedDriver_TurnOn(5);
  TEST_ASSERT_EQUAL_HEX16(0x0018,virtualLeds);
}

TEST(LedDriver, TurnOffLedOne) {
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  TEST_ASSERT_EQUAL_HEX16(0x0000,virtualLeds);
}

TEST(LedDriver, TurnOffMultipleLeds) {
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(5);
  LedDriver_TurnOff(1);
  LedDriver_TurnOff(5);
  TEST_ASSERT_EQUAL_HEX16(0x0000,virtualLeds);
}

TEST(LedDriver, CannotReadFromHardware) {
  virtualLeds = 0x1234;
  LedDriver_TurnOn(1);
  TEST_ASSERT_EQUAL_HEX16(0x0001,virtualLeds);
}

TEST(LedDriver, TurnOnAllLeds) {
  LedDriver_TurnOnAll();
  TEST_ASSERT_EQUAL_HEX16(0xffff,virtualLeds);
}

TEST(LedDriver, TurnOffAllLeds) {
  LedDriver_TurnOnAll();
  LedDriver_TurnOffAll();
  TEST_ASSERT_EQUAL_HEX16(0x0,virtualLeds);
}

