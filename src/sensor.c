/*
 * sensor.c
 *
 *  Created on: 6. 10. 2019
 *      Author: Petr Dvorak
 */

#include "sensor.h"

void sensor_config (void)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	NVIC_InitTypeDef   NVIC_InitStructure;

	// nastaveni citlivosti na vyber sensoru signalem LCD_CS
	// Enable AFIO clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	// Connect EXTI12 Line EXTI15_10_IRQn
	GPIO_EXTILineConfig(LCD_CS_PORTSOURCE, LCD_CS_PINSOURCE);

	// Configure EXTI12 line
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	// Enable and set EXTI0 Interrupt to the lowest priority
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void sensor_line_ready(uint8_t value)
{
	if (value == TRUE)
	{
		GPIO_SetBits(LCD_DC_PORT, LCD_DC_PIN);						// platny radek
	}
	else
	{
		GPIO_ResetBits(LCD_DC_PORT, LCD_DC_PIN);					// radek neni platny
	}
}
