#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver) {
  RUN_TEST_CASE(LedDriver, Create);
  RUN_TEST_CASE(LedDriver, TurnOnLedOne);
  RUN_TEST_CASE(LedDriver, TurnOnLedThree);
  RUN_TEST_CASE(LedDriver, TurnOnMultipleLeds);
  RUN_TEST_CASE(LedDriver, TurnOffLedOne);
  RUN_TEST_CASE(LedDriver, TurnOffMultipleLeds);
  RUN_TEST_CASE(LedDriver, CannotReadFromHardware);
  RUN_TEST_CASE(LedDriver, TurnOnAllLeds);
  RUN_TEST_CASE(LedDriver, TurnOffAllLeds);
}

static void RunAllTests(void) {
  RUN_TEST_GROUP(LedDriver);
}

int main(int argc, char* argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}
