#include "unity_fixture.h"
#include <stdint.h>

#include "LedDriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver) {

}

TEST_TEAR_DOWN(LedDriver) {

}

TEST(LedDriver, MyFirstFailingTest) {
  TEST_FAIL_MESSAGE("I am failing ^_^");
}