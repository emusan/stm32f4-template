/**
 * STM32F4 Template file by: Tom McLeod
 *
 * Borrowed heavily from the IO example provided by ST.
 *
 * This code will blink the 4 LED's on the STM32F4Discovery board repeatedly.
 *
 * If you end up using this code please let me know!
 *
 * That said, this isn't licensed, so feel free to do what you want :P.
 *
 * THIS CODE IS PROVIDED AS IS, WITH NO WARRANTY.
 **/ 

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

GPIO_InitTypeDef  GPIO_InitStructure;

void delay(float time);

int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);		// Start clock on GPIOD

	// This configures the Discovery LED pins D(12-15)
	// 12 = green/left
	// 13 = orange/top
	// 14 = red/right
	// 15 = blue/bottom
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	// Enable FPU :D
	// Not really used in this case, but doesn't hurt and proves that it works to 
	// some degree.
	SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));

	while (1)
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_12);	// Turn on green

		delay(0xFFFFF);

		GPIO_SetBits(GPIOD,GPIO_Pin_13);	// Turn on orange

		delay(0xFFFFF);

		GPIO_SetBits(GPIOD,GPIO_Pin_14);	// Turn on red

		delay(0xFFFFF);

		GPIO_SetBits(GPIOD,GPIO_Pin_15);	// Turn on blue

		delay(0xFFFFF);

		// Turn all off
		GPIO_ResetBits(GPIOD,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);

		delay(0xFFFFF);
	}
}

void delay(float time) 
{
	while(time--)
	{
	}
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{ 
	while (1)
	{
	}
}
#endif

