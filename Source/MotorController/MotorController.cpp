// MotorController.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MotorController.h"



CMotorController::CMotorController() :speed(0), direction(Forward)
{
}

void CMotorController::setSpeed(int speed)
{
    this->speed = speed;
}

int CMotorController::getSpeed()
{
    return speed;
}

void CMotorController::setDirection(Direction direction)
{
    this->direction = direction;
}

Direction CMotorController::getDirection()
{
    return direction;
}

bool CMotorController::getLimiter()
{
  return limiter;
}

Velocity CMotorController::getVelocity()
{
  return Velocity();
}


void CMotorController::checkSpeed()
{
  switch (speed)
  {
  case 10:
    limiter = false;
    velocity = Accelerate;
    break;
  case 50:
    {
      limiter = true;
      velocity = Decelerate;
    }
    break;
  default:
    ;

  }
}