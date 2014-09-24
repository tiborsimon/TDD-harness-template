#include "unity_fixture.h"

TEST_GROUP_RUNNER(LedDriver) {
  RUN_TEST_CASE(LedDriver, MyFirstFailingTest);
}

static void RunAllTests(void) {
  RUN_TEST_GROUP(LedDriver);
}

int main(int argc, char* argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}