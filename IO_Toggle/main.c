
#include "stm32f0xx_conf.h"
 
static unsigned char Led_State = 0x00;
  int i;
void TIM3_IRQHandler(void)
{
    if(TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) != RESET)
        Led_State ^= (1 << 0);
    TIM_ClearITPendingBit(TIM3, TIM_FLAG_Update);
}
 
void positive(){                           //function that provides '1' bit for neopixel
GPIO_SetBits(GPIOC, GPIO_Pin_8);
        for(i=0;i<4;i++);
GPIO_ResetBits(GPIOC, GPIO_Pin_8);
}
void negative(){                          //function that provides '0' bit for neopixel
     GPIO_SetBits(GPIOC, GPIO_Pin_8);
        for(i=0;i<1;i++);
     GPIO_ResetBits(GPIOC, GPIO_Pin_8);
	 
}
=======
#include "stm32f0xx.h"
#include <stm32f0xx_gpio.h>
#include <stm32f0xx_rcc.h>
#include <neolib.h>      //a library that was created is added to the project to use related functions 
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


void green(){    // a function was written for green color.
	    negative();
      negative();			
			negative();
      positive();      
      positive();
      negative();
      negative();
      negative();
      negative();	
      negative();
      negative();
      negative();
      negative();
      negative();	
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
			negative();

}
void blue(){                    //function was written for blue color
      negative();
      negative();			
			negative();
      negative();      
      negative();               // 24 bit was filled with smaller functions.
      negative();
      positive();
      negative();
      negative();	
      negative();
      negative();
      negative();
      negative();
      negative();	
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      positive();
      positive();
			positive();
}

void red(){                 //a function was written for red color
negative();
      negative();			
			negative();
      negative();      
      negative();
      negative();
      negative();
      negative();
      negative();	
      negative();
      negative();
      positive();
      negative();
      positive();	
      positive();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
      negative();
			negative();
}


int main(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM3_InitStructure;
    NVIC_InitTypeDef        NVIC_InitStructure;
 
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;              // GPIO pins is described here
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_1;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOC,&GPIO_InitStructure);
 
    TIM3_InitStructure.TIM_Prescaler         = 1;
    TIM3_InitStructure.TIM_CounterMode       = TIM_CounterMode_Up;
    TIM3_InitStructure.TIM_Period            = 1;
    TIM3_InitStructure.TIM_ClockDivision     = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM3, &TIM3_InitStructure);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
 
    NVIC_InitStructure.NVIC_IRQChannel          = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPriority  = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd       = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
 
   
 
    while(1)
    {
     green();
		 blue();
     blue();
     red();
     red();                            // 8 different color combination was created so a animation is got.
     blue();
     blue();
     green();
    			for(i=0;i<500000;i++);
		green();
		green();
     blue();
     blue();
		red();
		 red();
     blue();
		blue();
     
			for(i=0;i<5000000;i++);
			blue();
			green();
		green();
     blue();
     blue();
		red();
		 red();
     blue();
		
    for(i=0;i<500000;i++);
		blue();
		blue();
			green();
		green();
     blue();
     blue();
		red();
		 red();
     
		
    for(i=0;i<500000;i++);
   	red();
     blue();
		 blue();
			green();
		 green();
     blue();
     blue();
		red();
		 
		
    for(i=0;i<500000;i++);
		
		red();
		red();
     blue();
		 blue();
			green();
		 green();
     blue();
     blue();
		
		 
		
    for(i=0;i<500000;i++);
			 blue();
			 red();
		red();
     blue();
		 blue();
			green();
		 green();
     blue();
    
		 for(i=0;i<500000;i++);
			 blue();
			 blue();
			 red();
		red();
     blue();
		 blue();
			green();
		 green();
    
    
		
		 
		
    for(i=0;i<500000;i++);
    }
    return (0);
}
=======
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
int K[24]={80,0,0,80,0,0,80,0,0,80,0,0,80,0,0,80,0,0,80,0,0,80,0,0};   //an array was described to use in function
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
led(K);    // function that described in library is called for lighting neopixel
for(e=0;e<5100000;e++);       //make a delay for reset position of neopixel
 allblue(K); // another function called for changing array and get a new color combination.
	}
}

