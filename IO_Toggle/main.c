#include "stm32f0xx.h"
#include <stm32f0xx_gpio.h>
#include <stm32f0xx_rcc.h>
#include <neolib.h>
#include <string.h>




/** @addtogroup STM32F0_Discovery_Peripheral_Examples
  * @{0
  */

/** @addtogroup IO_Toggle
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BSRR_VAL        0x0300

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef        GPIO_InitStructure;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

GPIO_InitTypeDef Gp; //Create GPIO struct
TIM_TimeBaseInitTypeDef TIM3_InitStructure;
NVIC_InitTypeDef        NVIC_InitStructure;

//uint32_t* str[]={GPIO_Pin_8};

//Define LED pins
#define BlueLED_Pin GPIO_Pin_8
#define LED_GPIO GPIOC

//Define Push button
#define PushButton_Pin GPIO_Pin_0
#define PushButton_GPIO GPIOA
uint8_t ButtonRead = 0; //Initialize ButtonRead variable
uint8_t ButtonRead2 = 0;
int sayi=0;
int control;
int ara;
int ara2;
int e;
int K[24]={80,0,0,80,0,0,80,0,0,80,0,0,80,0,0,80,0,0,80,0,0,80,0,0};
int main(void)
{
	//Enable clocks to both GPIOA (push button) and GPIOC (output LEDs)
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

	Gp.GPIO_Pin = BlueLED_Pin; //Set pins inside the struct
	Gp.GPIO_Mode = GPIO_Mode_OUT; //Set GPIO pins as output
	Gp.GPIO_OType = GPIO_OType_PP; //Ensure output is push-pull vs open drain
	Gp.GPIO_PuPd = GPIO_PuPd_NOPULL; //No internal pullup resistors required
	Gp.GPIO_Speed = GPIO_Speed_50MHz; //Set GPIO speed to lowest
	GPIO_Init(LED_GPIO, &Gp); //Assign struct to LED_GPIO

	Gp.GPIO_Pin = PushButton_Pin; //Set pins inside the struct
	Gp.GPIO_Mode = GPIO_Mode_IN; //Set GPIO pins as output
	Gp.GPIO_PuPd = GPIO_PuPd_NOPULL; //No pullup required as pullup is external
	GPIO_Init(PushButton_GPIO, &Gp); //Assign struct to LED_GPIO

	

	while(1) //Infiinte loop!
	{
led(K);
for(e=0;e<5100000;e++);
 allblue(K);
	}
}
