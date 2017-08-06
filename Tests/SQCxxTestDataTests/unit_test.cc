#include "stdafx.h"
#include <iostream>
#include "component1.hh"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace SQCxxTestDataTests
{
  TEST_CLASS(Bar)
  {
  public:

    TEST_METHOD(foo)
    {
      // TODO: Your test code here
      Bar atest;
//      int value = atest.foo();
      Bar().foo();
    }

  };
}
