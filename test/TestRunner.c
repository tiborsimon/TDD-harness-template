#include "unity_fixture.h"

TEST_GROUP_RUNNER(MyModule) {
  RUN_TEST_CASE(MyModule, MyFirstFailingTest);
}

static void RunAllTests(void) {
  RUN_TEST_GROUP(MyModule);
}

int main(int argc, char* argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}