/*
	Anirban Saha
	Class Roll : 001520601011
	Problem 8 : To find the value of y'(x) using Richardson Interpolation 
*/

#include<stdio.h>
#include<math.h>

float funct(float x)
{
	return (-1/x);
}

int main()
{
	float h,g[20][20],x;
	int i,m,n;

	printf("\n\n Enter the Step Length h : ");
	scanf("%f",&h);

	printf("\n\n Enter the number of iterations : ");
	scanf("%d",&n);

	printf("\n\n Enter the point of evaluation : ");
	scanf("%f",&x);

	for(i=1;i<=n;i++){
		g[i][1] = (funct(x+h)-funct(x-h))/(2*h);
		h=h/2;
	}

	/* In the Following lines i denotes the power of h/(2^i) 
		and m denotes Fm(h/2^m) 
		The first Column hence is F1(h),F1(h/2),... 
		The iterating formula being 
			Fm(h/2^m) = ((4^m)*F(m-1)(h/2^m) - F(m-1)(h/2^(m-1)))/(4^m - 1)
	*/

	for(m=2;m<=n;m++)
		for(i=m;i<=n;i++)
			g[i][m] = ((pow(4,m-1)*g[i][m-1])-g[i-1][m-1])/(pow(4,m-1)-1);

	/* Now we print the matrix obtained as follows : 
		The first Column hence is F1(h),F1(h/2),... 
		The Second Column is F2(h),F2(h/2),.....
		and so on
	*/
	printf("\n\n");
	for(i=1;i<=n;i++){
		printf(" F[h/%1.0f] : ",pow(2,i-1));
		for(m=1;m<=i;m++)
			printf("%f \t",g[i][m]);
		printf("\n");
	}

	printf("\n\n The Solution is y'(%f) = %f\n\n",x,g[n][n]);
}

/* ~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~
ug-150@ug150-ThinkCentre-A51:~/anirbansaha$ ./richardson.out


 Enter the Step Length h : 0.005


 Enter the number of iterations : 5


 Enter the point of evaluation : 0.05


 F[h/1] : 404.040344 	
 F[h/2] : 401.002594 	399.990021 	
 F[h/4] : 400.249664 	399.998688 	399.999268 	
 F[h/8] : 400.062347 	399.999908 	400.000000 	400.000000 	
 F[h/16] : 400.015137 	399.999390 	399.999359 	399.999359 	399.999359 	


 The Solution is y'(0.050000) = 399.999359

*/
