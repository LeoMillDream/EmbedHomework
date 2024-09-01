#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_Init(void)
{
	PWM_Init();
}

void SetAngle(float angle)
{
	if(angle > 180)
		angle -= (float)180;
	else if(angle < 0)
		angle += (float)180;
	
	TIM_SetCompare2(TIM2, (uint16_t)(angle / 180 * 2000 + 500));
}
