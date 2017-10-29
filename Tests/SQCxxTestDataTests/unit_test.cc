#include "stdafx.h"
#include <iostream>
#include <gtest/gtest.h>
#include "component1.hh"


class SQCxxTestDataTests : public ::testing::Test {

protected:

  virtual void SetUp() {

  }

  virtual void TearDown() {
    // Code here will be called immediately after each test 
    // (right before the destructor). 
  }
};


TEST_F(SQCxxTestDataTests, foo) {

  Bar atest;
  Bar().foo();

}

//namespace SQCxxTestDataTests
//{
//  TEST_CLASS(Bar)
//  {
//  public:
//
//    TEST_METHOD(foo)
//    {
//      // TODO: Your test code here
//      Bar atest;
////      int value = atest.foo();
//      Bar().foo();
//    }
//
//  };
//}
