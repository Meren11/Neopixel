#include "stm32f0xx_conf.h"
 
//static unsigned char Led_State = 0x00;
  int i;
	int j;
	int m;
	int n;
	int l;
	int t=0;
	int p=0;
	int r=0;
	int A[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int B[24];
	
void TIM3_IRQHandler(void)
{
    if(TIM_GetFlagStatus(TIM3, TIM_FLAG_Update) != RESET)
//        Led_State ^= (1 << 0);
    TIM_ClearITPendingBit(TIM3, TIM_FLAG_Update);
}

void police(){
		if(p%2==0)	{
	   for(t=0;t<4;t++){
	     A[3*t]=0;
	     A[3*t+1]=120;
       A[3*t+2]=0;		
	}
			for(t=4;t<8;t++){
	      A[3*t]=0;
	      A[3*t+1]=0;
        A[3*t+2]=80;		
	}}
			
		if(p%2==1){
			for(t=4;t<8;t++){
	     A[3*t]=0;
	     A[3*t+1]=120;
       A[3*t+2]=0;		
	}
			for(t=0;t<4;t++){
	      A[3*t]=0;
	      A[3*t+1]=0;
        A[3*t+2]=80;		
	}}
			p++;
    	
}
void allgreen(){
	for(t=0;t<8;t++){
	A[3*t]=80;
	A[3*t+1]=0;
A[3*t+2]=0;		
	}
}
void allblue(){
	for(t=0;t<8;t++){
	A[3*t]=0;
	A[3*t+1]=0;
A[3*t+2]=80;		
	}
}
void allred(){
	for(t=0;t<8;t++){
	A[3*t]=0;
	A[3*t+1]=80;
A[3*t+2]=0;		
	}
}

void demo1(){
 if(t<23){
		A[t+3]=A[t];
		A	[t]=0;
			t=t+3;
			 }
		else if(t>=23&&p<22) {
		A[t]=A[t];
			
			A[p+3]=A[p];
		  A[p]=0;
			p=p+3;
		}
    else if(r<23) {
			A[r+3]=A[r];
		A	[r]=0;
			r=r+3;
		}	
}
void led( ){
	 	
		 for(i=0;i<24;i++){
		B[i]=A[i];
	   for(j=0;j<8;j++){
		    if(B[i]>127){
				    
						GPIOC -> BSRR = GPIO_Pin_8;
               for(l=0;l<9;l++);
             GPIOC -> BRR = GPIO_Pin_8;
				       
				      }
				else {
				    GPIOC -> BSRR = GPIO_Pin_8;
					     for(n=0;n<5;n++);
            GPIOC -> BRR = GPIO_Pin_8;
					       for(n=0;n<4;n++);
				     }
				B[i]=B[i]<<1;
				 		 
		  }
		}
		for(n=0;n<510;n++);
	}

