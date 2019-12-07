/*   Anirban Saha
	Class Roll : 001520601011
	Problem 5 :  To interpolate a value using the Lagrange Interpolation Method .
*/


#include<stdio.h>
#include<math.h>

int main()
{
	float x[20],y[20],s[20],x1,sum=0;
	int i,j,n;

	printf("\n\n Enter the number of records : \n");
	scanf("%d",&n);

	printf("\n Enter the values of x and y : \n");
	for(i=1;i<=n;i++){
		printf("\n x[%d] :  ",i);
		scanf("%f",&x[i]);

		printf("\n y[%d] :  ",i);
		scanf("%f",&y[i]);
	}

	printf("\n\n Enter the value of x for finding y(x) : ");
	scanf("%f",&x1);

	for(i=1;i<=n;i++){
		s[i]=1;
		for(j=1;j<=n;j++)
			if(i!=j)
				s[i] = s[i]* ((x1-x[j])/(x[i]-x[j]));
		sum = sum + (s[i]*y[i]);
	}

	printf("\n\n y[%f] = %f \n\n",x1,sum);
	return 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~
ug-150@ug150-ThinkCentre-A51:~/anirbansaha$ ./lagrange_interpolation.out


 Enter the number of records : 
4

 Enter the values of x and y : 

 x[1] :  -2

 y[1] :  5

 x[2] :  1

 y[2] :  7

 x[3] :  3

 y[3] :  11

 x[4] :  7

 y[4] :  34


 Enter the value of x for finding y(x) : 0


 y[0.000000] = 6.038889 

*/
