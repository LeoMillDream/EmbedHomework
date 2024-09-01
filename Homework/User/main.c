#include "stm32f10x.h"
#include "Timer.h"
#include "MPU6050.h"
#include "OLED.h"
#include "Servo.h"

float angleZ = 0;

int main(void)
{
    Timer_Init();
    MPU6050_Init();
    OLED_Init();
	Servo_Init();

    OLED_ShowString(1, 1, "Yaw Angle:");

    while (1)
    {
        angleZ = CalculateAngle(angleZ);
		SetAngle(angleZ);
    }
}
