#include "stdafx.h"
#include <CppUnitTest.h>
#include <MotorController.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework
        {
            template<> static std::wstring ToString<Direction>(const Direction& direction)
            {
                return direction == Forward ? L"F" : L"R";
            };
        }
    }
}


namespace MotorControllerTests
{		
    TEST_CLASS(MotorControllerTest)
    {
    public:
        
    public:
        TEST_METHOD(getSpeed)
        {
            CMotorController motor;
            motor.setSpeed(123);

            Assert::AreEqual(123, motor.getSpeed());
        }

        TEST_METHOD(getDirection)
        {
            CMotorController motor;
            motor.setDirection(Forward);

            Assert::AreEqual(Forward, motor.getDirection());
        }


    };
}