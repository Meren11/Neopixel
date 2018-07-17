#include "stm32f0xx_conf.h"

 
static unsigned char Led_State = 0x00;
  int i;
void TIM3_IRQHandler(void)
{
    if(TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) != RESET)
        Led_State ^= (1 << 0);
    TIM_ClearITPendingBit(TIM3, TIM_FLAG_Update);
}

void led(int u,int A[]){
for(i=0;i<24;i++){
		B[i]=A[i];
	   for(j=0;j<8;j++){
		    if(B[i]>127){
					if(u%3!=0){
						GPIOC -> BSRR = GPIO_Pin_8;}
              if(u%3=0){
             GPIOC -> BRR = GPIO_Pin_8;}
				       
				      }
				else {
					if(u%3!=0){
				    GPIOC -> BSRR = GPIO_Pin_8;}
					     if(u%3!=0){
            GPIOC -> BRR = GPIO_Pin_8;}
					       
				     }
				B[i]=B[i]<<1;
				 		 
		  }
		}
		

}

	 


int A[24]={0};
int y;
int i;
int main(void)
{
    GPIO_InitTypeDef        GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM3_InitStructure;
    NVIC_InitTypeDef        NVIC_InitStructure;
 
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
 
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
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
					if(Led_State==0x01){
			y++;
		}
     led(y,A);
		for(i=0;i<510;i++);
  
		if(y==3){
		y=1;
		}

  			
			
    }
    return (0);
}