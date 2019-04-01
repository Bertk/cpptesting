#include "stdafx.h"
#include <CppUnitTest.h>
#include <MotorController.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework
        {
            template<> std::wstring ToString<Direction>(const Direction& direction)
            {
                return direction == Forward ? L"F" : L"R";
            };
            template<> std::wstring ToString<Velocity>(const Velocity& velocity)
            {
              return velocity == Accelerate ? L"A" : L"D";
              //if (velocity == Accelerate)
              //  return L"A";
              //if (velocity == Normal)
              //  return L"N";
              //if (velocity == Decelerate)
              //  return L"D";
            };
        }
    }
}


namespace MotorControllerTests
{		
    TEST_CLASS(MotorControllerTest)
    {
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

        //TEST_METHOD(getVelocity)
        //{
        //  CMotorController motor;

        //  motor.setSpeed(50);
        //  motor.checkSpeed();

        //  Assert::AreEqual(Decelerate, motor.getVelocity());
        //}

        TEST_METHOD(getLimiter)
        {
          CMotorController motor;

          motor.setSpeed(50);
          motor.checkSpeed();
          Assert::AreEqual(true, motor.getLimiter());

          motor.setSpeed(10);
          motor.checkSpeed();
          Assert::AreEqual(false, motor.getLimiter());

          motor.setSpeed(20);
          motor.checkSpeed();
          Assert::AreEqual(false, motor.getLimiter());
        }

    };
}
