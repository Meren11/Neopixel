#include "stm32f0xx_conf.h"

int i;
	int j;
	int m;
	int u;
	int l;
	int t=2;
	int p=1;
	int r=0;
	int B[24];
int pin;
	

void police(int A[]){
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
void allgreen(int A[]){
	for(t=0;t<8;t++){
	A[3*t]=80;
	A[3*t+1]=0;
A[3*t+2]=0;		
	}
}
void allblue(int A[]){
	for(t=0;t<8;t++){
	A[3*t]=0;
	A[3*t+1]=0;
A[3*t+2]=80;		
	}
}
void allred(int A[]){
	for(t=0;t<8;t++){
	A[3*t]=0;
	A[3*t+1]=80;
A[3*t+2]=0;		
	}
}

void demo1(int A[]){
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
void led(int A[] ){
	 	
		 for(i=0;i<24;i++){
		B[i]=A[i];
	   for(j=0;j<8;j++){
		    if(B[i]>127){
				    
						GPIOC -> BSRR = BlueLED_Pin;
               for(l=0;l<9;l++);
             GPIOC -> BRR = BlueLED_Pin;
				       
				      }
				else {
				    GPIOC -> BSRR = BlueLED_Pin;
					     for(u=0;u<5;u++);
            GPIOC -> BRR = BlueLED_Pin;
					       for(u=0;u<4;u++);
				     }
				B[i]=B[i]<<1;
				 		 
		  }
		}
		
	}

