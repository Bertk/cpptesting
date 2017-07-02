// MotorController.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "MotorController.h"



CMotorController::CMotorController()
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

