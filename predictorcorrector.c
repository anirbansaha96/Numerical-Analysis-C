/*	Class Roll : 001520601011
	Anirban Saha
	Problem 17 : To Solve a differential Equation [ dy/dx = (x+y) ] using 
				 Predictor-Corrector Method
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
	float x[20],y[20],yd[20],endpoint,yp[20],yc[20],ypd[20],h;
	int i,n;

	for(i=0;i<=3;i++){
		printf("\nPlease enter value of x,y for n=%d : ",i);
		scanf("%f%f",&x[i],&y[i]);
	}


	/* ~~~~~~~~ Displaying The Given Values ~~~~~~~~~~~~~~~~ */
	printf("\n\n");
	
	printf("\n n  ");
	for(i=0;i<=3;i++)
		printf("|\t%d\t",i);
	printf("\n x  ");
	for(i=0;i<=3;i++)
		printf("|\t%f",x[i]);
	printf("\n y  ");
	for(i=0;i<=3;i++)
		printf("|\t%f",y[i]);
	printf("\n y' ");
	for(i=0;i<=3;i++){
		yd[i]=function(x[i],y[i]);
		printf("|\t%f",yd[i]);
	}
	printf("\n\n");
	

	printf(" Please enter the point of evaluation : ");
	scanf("%f",&endpoint);
	printf("\n Please enter the step Length : ");
	scanf("%f",&h);
	

	n=3;

	printf("\n\n yd[1] = %f\n\n",yd[1]);
	yp[n+1] = y[n-3] + (4*h/3)*( 2*yd[n-2] - yd[n-1] + 2*yd[n]);
	x[n+1] = x[n] + h;	
	ypd[n+1] = function(x[n+1],yp[n+1]);
	yc[n+1] = y[n-1] + (h/3)*(ypd[n+1] + 4*yd[n] + yd[n-1]);
	printf("\n\n yc[%d] = %f ",n+1,yc[n+1]);
	printf("\n\n | yc[%d] - yp[%d] | = %f",n+1,n+1,fabs(yc[n+1]-yp[n+1]));

	while(fabs(yc[n+1]-yp[n+1]) > ERR ){
		yp[n+1]=yc[n+1];
		printf("\n\n yp[%d] = %f ",n+1,yp[n+1]);

		ypd[n+1] = function(x[n+1],yp[n+1]);
		yc[n+1] = y[n-1] + (h/3)*(ypd[n+1] + 4*yd[n] + yd[n-1]);
		printf("\n\n yc[%d] = %f ",n+1,yc[n+1]);
		printf("\n\n | yc[%d] - yp[%d] | = %f",n+1,n+1,fabs(yc[n+1]-yp[n+1]));

	}
	printf("\n\n The value is : %f \n\n",yc[n+1]);
	
	return 0;


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~

Please enter value of x,y for n=0 : 0 1

Please enter value of x,y for n=1 : 0.1 1.1103

Please enter value of x,y for n=2 : 0.2 1.2428

Please enter value of x,y for n=3 : 0.3 1.3997



 n  |	0	|	1	|	2	|	3	
 x  |	0.000000|	0.100000|	0.200000|	0.300000
 y  |	1.000000|	1.110300|	1.242800|	1.399700
 y' |	1.000000|	1.210300|	1.442800|	1.699700

 Please enter the point of evaluation : 0.4

 Please enter the step Length : 0.1


 yd[1] = 1.210300



 yc[4] = 1.583641 

 | yc[4] - yp[4] | = 0.000014

 yp[4] = 1.583641 

 yc[4] = 1.583641 

 | yc[4] - yp[4] | = 0.000000

 The value is : 1.583641 

*/
