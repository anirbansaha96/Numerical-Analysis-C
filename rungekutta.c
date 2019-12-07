/*  Class Roll : 001520601011
	Anirban Saha
	Problem 16 : To Solve a differential Equation [ dy/dx = (x+y) ] using 
				 Runge-Kutta's Method
*/

#include<stdio.h>
#include<math.h>
#define ERR 0.000001
float function(float x,float y)
{
	float value;
	value = x + y;			/* dy/dx = f(x,y) = x + y ; */
	return value;
}

int main()
{
	float v1,v2,v3,v4,y[20],x[20],h,end;
	int i,n;
	x[0] = 0;
	y[0] = 1;
	h=0.1;
	
	printf("\n Enter the point where you want to evaluate y(x) : ");
	scanf("%f",&end);

	n = end/h;
	for(i=0;i<n;){	
		v1 = function(x[i],y[i]);
		v2 = function(x[i] + (h/2) ,y[i] + ((v1*h)/2));
		v3 = function(x[i] + (h/2) ,y[i] + ((v2*h)/2));
		v4 = function(x[i] + h ,y[i] + h*v3);
		i++;
		x[i] = x[i-1] + h;
		printf("\n v1 = %f \n v2 = %f \n v3 = %f \n v4 = %f",v1,v2,v3,v4);
		y[i] = y[i-1] + (h/6)*( v1 + 2*v2 + 2*v3 + v4);
		printf("\n y[%d] = %f \n",i,y[i]);
	}

	printf("\n\n The Value of y[%f] = %f \n\n",end,y[i]);

	return 0;
}
		
/* ~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 Enter the point where you want to evaluate y(x) : 0.4

 v1 = 1.000000 
 v2 = 1.100000 
 v3 = 1.105000 
 v4 = 1.210500
 y[1] = 1.110342 

 v1 = 1.210342 
 v2 = 1.320859 
 v3 = 1.326385 
 v4 = 1.442980
 y[2] = 1.242805 

 v1 = 1.442805 
 v2 = 1.564945 
 v3 = 1.571052 
 v4 = 1.699910
 y[3] = 1.399717 

 v1 = 1.699717 
 v2 = 1.834703 
 v3 = 1.841452 
 v4 = 1.983862
 y[4] = 1.583648 


 The Value of y[0.400000] = 1.583648 

*/
