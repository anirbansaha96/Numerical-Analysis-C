/*   Anirban Saha
	Class Roll : 001520601011
	Problem 7 :  To interpolate a value using the Hermite Interpolation Method .
*/
 
#include<stdio.h>
#include<math.h>

int main()
{
	float x[20],y[20],dy[20],li,x1,h[50],g[50],y1,sum;
	int i,j,n;

	printf("\n\n Enter the degree of Polynomial : ");
	scanf("%d",&n);

	printf("\n Enter the values of x and y and y': \n");
	for(i=0;i<n;i++){
		printf("\n x[%d] :  ",i);
		scanf("%f",&x[i]);

		printf("\n y[%d] :  ",i);
		scanf("%f",&y[i]);

		printf("\n yd[%d] :  ",i);
		scanf("%f",&dy[i]);
	}

	printf("\n\n Enter the value of x for finding y(x) : ");
	scanf("%f",&x1);
	for(i=0;i<n;i++){
		li=1;sum=0;
		for(j=0;j<n;j++){
			if(j!=i){
				li=li*(x1-x[j])/(x[i]-x[j]);
				sum=sum+1/(x[i]-x[j]);
			}
		}
		li=li*li;
		g[i]=(1-2*(x1-x[i])*sum)*li;
		h[i]=(x1-x[i])*li;
	}
	y1=0;
	for(i=0;i<n;i++)
	y1=y1+y[i]*g[i]+dy[i]*h[i];
	printf("The value is %f\n",y1);

	
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
ug-150@ug150-ThinkCentre-A51:~/anirbansaha$ ./hermite.out


 Enter the degree of Polynomial : 3

 Enter the values of x and y and y': 

 x[0] :  1

 y[0] :  4

 yd[0] :  7

 x[1] :  2

 y[1] :  5

 yd[1] :  8

 x[2] :  3

 y[2] :  6

 yd[2] :  9


 Enter the value of x for finding y(x) : 2.5
The value is 7.046875
*/
