/*  Anirban Saha
	Class Roll : 001520601011
	Problem 4 : To find the solution of a problem by Newton Raphson Method correct upto 4 decimal place
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ERR 0.00001 
float func(float x)
{
	float value;
	value= x*x*x - 3*x + 1;
	return value;
}

float derivative(float x)
{
	float value;
	value= 3*x*x - 3;
	return value;
}

float ddr(float x)
{
	float value;
	value= 6*x;
	return value;
}

int main()
{
	float root[100],x,e,a,b,c;
	int i=0;
	printf("\nPlease enter an initial value : ");
	scanf("%f",&root[0]);
	a= func(root[0]);
	b= ddr(root[0]);
	c= derivative(root[0]);
	e= (a*b)/(c*c);
	e= fabs(e);
	if(e>1){
		printf("\n It violates the condition for convergency \n");
		exit;
	}
	printf("\n\nNo.\tx[i]\t\t-(f(x)/f'(x))\tx[i+1]\t\tf(x[i+1])\tERROR\n");
	while(e<1){
		x= - (func(root[i])/derivative(root[i]));
		root[i+1]=root[i] + x;
		printf("%d\t%f\t%f\t%f\t%f\t%f\n",i,root[i],x,root[i+1],func(root[i+1]),fabs(root[i+1]-root[i]));
		i++;
		if((fabs(root[i]-root[i-1])<ERR) && (i>0))
			break;
	}
	
	printf("\nThe root is %f\n\n",root[i]);
	return 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~
Please enter an initial value : 2


No.	x[i]		-(f(x)/f'(x))	x[i+1]		f(x[i+1])	ERROR
0	2.000000	-0.333333	1.666667	0.629629	0.333333
1	1.666667	-0.118056	1.548611	0.068040	0.118055
2	1.548611	-0.016221	1.532390	0.001218	0.016221
3	1.532390	-0.000301	1.532089	0.000000	0.000301
4	1.532089	-0.000000	1.532089	-0.000000	0.000000

The root is 1.532089

*/
