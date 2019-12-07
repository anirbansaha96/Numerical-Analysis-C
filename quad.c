/* 	Anirban Saha
	Class Roll : 001520601011
	Problem 10 : To Find the value of an Integral Using Gauss Quadrature Method.
*/
#include<stdio.h>
#include<math.h>

float a,b;

float func(float x)
{
	return (1/(1+x*x));
}

float h(float a,float b,float x)
{
	float answer;
	answer = func(  ( (b-a)*x/2 ) + (b+a)/2   ) * ((b-a)/2);
	return answer;
}

float g(float x)
{	
	return h(a,b,x);
}
int main()
{
	float x1,x2,answer;
	int n;

	printf("\n\n Enter the Interval a,b : ");
	scanf("%f%f",&a,&b);
	printf("\n\n Enter the value of n : ");
	scanf("%d",&n);

	/* Now we Transform the interval to (-1,1) */

	switch(n){
		case 1	: 	answer = 2* g(0);
					break;
		case 2 	: 	answer = g(-1/pow(3,0.5)) + g(1/pow(3,0.5));
					break;
		case 3	: 	answer = (5.0/9.0)*g(-pow(3/5,0.5)) + (8.0/9.0)*g(0) + (5.0/9.0)*g(pow(3/5,0.5));
					break;
		case 4 	:	answer = 0.652145*(g(0.339981)+g(-0.339981)) +0.347855*( g(-0.861136) + g(0.861136) );
					break;
	}
	
	printf("\n\n The Value is : %f \n\n",answer);
}

/* ~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~
ug-150@ug150-ThinkCentre-A51:~/anirbansaha$ ./quad.out


 Enter the Interval a,b : 0 1


 Enter the value of n : 4


 The Value is : 0.785403

*/
