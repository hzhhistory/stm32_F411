#include "stm32f4xx.h"

void delay(uint8_t ms);

int main()
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    u8 k=30;
	while(1)
	{
        for(u8 i=0;i<k;i++)
        {
            GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_SET);
            delay(i);
            GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_RESET);
            delay(k-i);
        }
        for(u8 i=0;i<k;i++)
        {
            GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_RESET);
            delay(i);
            GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_SET);
            delay(k-i);
        }

	}
}

void delay(uint8_t ms)
{
    while(ms)
    {
        for(uint8_t i;i<0xFFF;i++)
        {
            ms++;
        }

    }
}