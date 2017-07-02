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

// This class is exported from the MotorController.dll
class MOTORCONTROLLER_API CMotorController {
private:
    int speed;
    Direction direction;
public:
    CMotorController(void);

    void setSpeed(int speed);
    int getSpeed();

    void setDirection(Direction direction);
    Direction getDirection();
};

