// MotorController.h

#ifdef MOTORCONTROLLER_EXPORTS
#define MOTORCONTROLLER_API __declspec(dllexport)
#else
#define MOTORCONTROLLER_API __declspec(dllimport)
#endif

enum Direction
{
    Forward,
    Reverse
};

enum Velocity
{
  Accelerate,
  Decelerate
};

// This class is exported from the MotorController.dll
class MOTORCONTROLLER_API CMotorController {
private:
    int speed;
    Direction direction;
    bool limiter;
    Velocity velocity;

public:
    CMotorController(void);

    void setSpeed(int speed);
    int getSpeed();
    void checkSpeed();
    bool getLimiter();
    Velocity getVelocity();

    void setDirection(Direction direction);
    Direction getDirection();
};

