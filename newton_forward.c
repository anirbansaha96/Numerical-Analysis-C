/*   Anirban Saha
	Class Roll : 001520601011
	Problem 6 :  To interpolate a value using the Newton Forward Interpolation 
			   Method .
*/
 
#include<stdio.h>
#include<math.h>

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

int main()
{
	float x[20],y[20][20],s[20],x1,h,u,temp,sum=0;
	int i,j,n;

	printf("\n\n Enter the number of records : ");
	scanf("%d",&n);

	printf("\n Enter the values of x and y : \n");
	for(i=0;i<n;i++){
		printf("\n x[%d] :  ",i);
		scanf("%f",&x[i]);

		printf("\n y[%d] :  ",i);
		scanf("%f",&y[i][0]);
	}

	printf("\n\n Enter the value of x for finding y(x) : ");
	scanf("%f",&x1);

	for(j=0;j<n;j++)
		for(i=0;i<n;i++)
			y[i+1][j+1]=y[i+1][j]-y[i][j];

	printf("\t x\t\t y");
	for(i=1;i<n;i++)
		printf("\t\t yi[%d]",i);
	printf("\n");

	for(i=0;i<n;i++){
		printf("\t %f",x[i]);
		for(j=0;j<=i;j++)
			printf("\t %f",y[i][j]);
		printf("\n");
	}
	h=x[1]-x[0];
	u=(x1-x[0])/h;
	for(i=0;i<n;i++){
		temp=1;
		for(j=0;j<i;j++)
			temp=temp*(u-j);
		sum=sum+((temp*y[i][j])/fact(i));
	}
	printf("\n y[%f]=%f\n\n",x1,sum);

}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~
ug-150@ug150-ThinkCentre-A51:~/anirbansaha$ ./newton_forward.out


 Enter the number of records : 4

 Enter the values of x and y : 

 x[0] :  20

 y[0] :  24

 x[1] :  24

 y[1] :  32

 x[2] :  28

 y[2] :  35

 x[3] :  32

 y[3] :  40


 Enter the value of x for finding y(x) : 25
	 x			 y		 	yi[1]		 yi[2]		 yi[3]
	 20.000000	 24.000000
	 24.000000	 32.000000	 8.000000
	 28.000000	 35.000000	 3.000000		 -5.000000
	 32.000000	 40.000000	 5.000000		 2.000000	 	7.000000

 y[25.000000]=32.945312
*/	
