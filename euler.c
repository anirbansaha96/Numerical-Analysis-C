/*  Anirban Saha
	Class Roll : 001520601011
	Problem 15 : To Solve a differential Equation [ dy/dx = (x+y) ] using 
				 Euler's Method
*/

#include<stdio.h>
#include<math.h>

float function(float x,float y)
{
	float value;
	value = x + y;		/* dy/dx = x + y ; */
	return value;
}

int main()
{
	int i=0;
	float h,y[100],x[100],end;
	y[0]=1;
	x[0]=0;	

	printf("\nPlease enter the step length h : ");
	scanf("%f",&h);
	printf("\nPlease enter the value of x where you wish to find y(x) : " );
	scanf("%f",&end);
	printf("\n N \t x \t\t y \n");
	while(1){	
		printf(" %d \t %f \t %f \n",i,x[i],y[i]);
		i++;		
		x[i]= x[i-1] + h;
		y[i]=y[i-1]+h*function(x[i-1],y[i-1]);
		if(x[i]>end)
			break;
		
	}

	printf("\n\n The value of y(%f) = %f \n",end,y[i-1]);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter the step length h : 0.05

Please enter the value of x where you wish to find y(x) : 0.3

 N 	 x 		 y 
 0 	 0.000000 	 1.000000 
 1 	 0.050000 	 1.050000 
 2 	 0.100000 	 1.105000 
 3 	 0.150000 	 1.165250 
 4 	 0.200000 	 1.231012 
 5 	 0.250000 	 1.302563 
 6 	 0.300000 	 1.380191 


 The value of y(0.300000) = 1.380191 
*/
