/* Class Roll : 001520601011
   Anirban Saha
   Problem 14 : To Find The Maximum Eigen Value of a Matrix using Power Method
*/


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define ERR 0.0001

int main()
{
	float A[15][15],V[15][15],y[15][15],sum,max,value[15],EigenValue;
	int i,j,k,n,end;
	
	printf("\n Please enter the order of the Matrix : ");
	scanf("%d",&n);

	/* ~~~~~~~~~~~~	 Accepting Matrix A   ~~~~~~~~~~~~~ */
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("\n A[%d][%d] : ",i,j);
			scanf("%f",&A[i][j]);
		}
	}

	/* ~~~~~~~~~~~~  Printing Matrix A    ~~~~~~~~~~~~~ */	
	for(i=1;i<=n;i++){
		printf("\n[\t");
		for(j=1;j<=n;j++)
			printf("%f\t ",A[i][j]);
		printf("]");
	}
	printf("\n\n");
	
	/* ~~~~~~~~~~~~~~   Defining V   ~~~~~~~~~~~~~~~~~~~ */
	
	for(i=1;i<=n;i++)
		V[0][i]=1;

	/* ~~~~~~~~ Power Method Algorithm Starts ~~~~~~~~~~ */
	for(k=1;k<=50;k++){
		for(i=1;i<=n;i++){
			sum=0;
			for(j=1;j<=n;j++)
				sum = sum + A[i][j]*V[k-1][j]; /* yk = A * v(k-1) */
			y[k][i] = sum;
		}
		/* ~~~~~ Printing y Matrix ~~~~~~ */	
		printf("\n\n y%d : ",k);
		for(i=1;i<=n;i++)
			printf("\n | \t %f \t | ",y[k][i]);
		printf("\n\n");

		max=fabs(y[k][1]);
		
	
		for(i=1;i<=n;i++)
			if(max < fabs(y[k][i]))
				max=fabs(y[k][i]);
		/* ~~~~~~ Finding V Vector ~~~~~~ */		
		for(i=1;i<=n;i++)
			V[k][i] = y[k][i]/max;

		/* ~~~~~ Printing V Vector ~~~~~~ */	
		printf("\n\n V%d : ",k);
		for(i=1;i<=n;i++)
			printf("\n | \t %f \t | ",V[k][i]);
		printf("\n\n");
		
		/* ~~~~~ Finding Loop End ~~~~~~~ */
		end=0;
		for(i=1;i<=n;i++)
			if(fabs(fabs(V[k-1][i])-fabs(V[k][i])) < ERR)
				end++;
		if(end==n){
			printf("\nEnd Found ");
			break;
		}

	}

	for(i=1;i<=n;i++)
		value[i]= y[k][i] / V[k-1][i];
	max = 0;
	for(i=1;i<=n;i++){
		if(max < fabs(value[i]))
 			max=fabs(value[i]);
	}

	EigenValue=max;
	printf("\n\nThe Maximum Eigen Value is %f\n\n",EigenValue);

	return 0;
}

/* ~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~ 

 Please enter the order of the Matrix : 3

 A[1][1] : -15

 A[1][2] : 4

 A[1][3] : 3

 A[2][1] : 10

 A[2][2] : -12

 A[2][3] : 6

 A[3][1] : 20

 A[3][2] : -4

 A[3][3] : 2

[	-15.000000	 4.000000	 3.000000	 ]
[	10.000000	 -12.000000	 6.000000	 ]
[	20.000000	 -4.000000	 2.000000	 ]



 y1 : 
 | 	 -8.000000 	 | 
 | 	 4.000000 	 | 
 | 	 18.000000 	 | 



 V1 : 
 | 	 -0.444444 	 | 
 | 	 0.222222 	 | 
 | 	 1.000000 	 | 



 y2 : 
 | 	 10.555555 	 | 
 | 	 -1.111111 	 | 
 | 	 -7.777779 	 | 



 V2 : 
 | 	 1.000000 	 | 
 | 	 -0.105263 	 | 
 | 	 -0.736842 	 | 



 y3 : 
 | 	 -17.631580 	 | 
 | 	 6.842104 	 | 
 | 	 18.947369 	 | 



 V3 : 
 | 	 -0.930556 	 | 
 | 	 0.361111 	 | 
 | 	 1.000000 	 | 



 y4 : 
 | 	 18.402779 	 | 
 | 	 -7.638889 	 | 
 | 	 -18.055557 	 | 



 V4 : 
 | 	 1.000000 	 | 
 | 	 -0.415094 	 | 
 | 	 -0.981132 	 | 



 y5 : 
 | 	 -19.603773 	 | 
 | 	 9.094339 	 | 
 | 	 19.698112 	 | 



 V5 : 
 | 	 -0.995211 	 | 
 | 	 0.461686 	 | 
 | 	 1.000000 	 | 



 y6 : 
 | 	 19.774904 	 | 
 | 	 -9.492337 	 | 
 | 	 -19.750957 	 | 



 V6 : 
 | 	 1.000000 	 | 
 | 	 -0.480019 	 | 
 | 	 -0.998789 	 | 



 y7 : 
 | 	 -19.916445 	 | 
 | 	 9.767499 	 | 
 | 	 19.922501 	 | 



 V7 : 
 | 	 -0.999696 	 | 
 | 	 0.490275 	 | 
 | 	 1.000000 	 | 



 y8 : 
 | 	 19.956539 	 | 
 | 	 -9.880257 	 | 
 | 	 -19.955019 	 | 



 V8 : 
 | 	 1.000000 	 | 
 | 	 -0.495089 	 | 
 | 	 -0.999924 	 | 



 y9 : 
 | 	 -19.980125 	 | 
 | 	 9.941521 	 | 
 | 	 19.980507 	 | 



 V9 : 
 | 	 -0.999981 	 | 
 | 	 0.497561 	 | 
 | 	 1.000000 	 | 



 y10 : 
 | 	 19.989958 	 | 
 | 	 -9.970541 	 | 
 | 	 -19.989862 	 | 



 V10 : 
 | 	 1.000000 	 | 
 | 	 -0.498777 	 | 
 | 	 -0.999995 	 | 



 y11 : 
 | 	 -19.995094 	 | 
 | 	 9.985358 	 | 
 | 	 19.995119 	 | 



 V11 : 
 | 	 -0.999999 	 | 
 | 	 0.499390 	 | 
 | 	 1.000000 	 | 



 y12 : 
 | 	 19.997540 	 | 
 | 	 -9.992665 	 | 
 | 	 -19.997534 	 | 



 V12 : 
 | 	 1.000000 	 | 
 | 	 -0.499695 	 | 
 | 	 -1.000000 	 | 



 y13 : 
 | 	 -19.998779 	 | 
 | 	 9.996339 	 | 
 | 	 19.998779 	 | 



 V13 : 
 | 	 -1.000000 	 | 
 | 	 0.499847 	 | 
 | 	 1.000000 	 | 



 y14 : 
 | 	 19.999390 	 | 
 | 	 -9.998169 	 | 
 | 	 -19.999390 	 | 



 V14 : 
 | 	 1.000000 	 | 
 | 	 -0.499924 	 | 
 | 	 -1.000000 	 | 


End Found 

The Maximum Eigen Value is 20.002441
*/
