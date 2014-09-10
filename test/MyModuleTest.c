#include "unity_fixture.h"
#include <stdint.h>

#include "MyModule.h"

TEST_GROUP(MyModule);

TEST_SETUP(MyModule) {

}

TEST_TEAR_DOWN(MyModule) {

}

TEST(MyModule, MyFirstFailingTest) {
  TEST_FAIL_MESSAGE("I am failing ^_^");
}