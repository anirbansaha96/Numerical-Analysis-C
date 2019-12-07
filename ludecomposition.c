/* 	Anirban Saha
	Class Roll : 001520601011
	Problem 12 : To Find The Solution of a system of Linear Equations 
				 using LU Decomposition 
*/

#include<stdio.h>

int main()
{
	float a[15][15],b[15],multiplier,multipliers[15][15],root[15],sum,l[15][15],u[15][15],y[15],c[15],temp;
	int i,j,k,n,p,q,index;
	printf("\n\nPlease enter the number of variables : ");
	scanf("%d",&n);
	
	/* ~~~~~~~~~~~~~~~~ Accepting Equations ~~~~~~~~~~~~~~~~~~~ */
	for(i=1;i<=n;i++){
		printf("\n Enter the coefficients of the variables in this equation :\n");
		for(j=1;j<=n;j++)
			scanf("%f",&a[i][j]);
		printf("\nEnter the Constant in the equation : \n");
		scanf("%f",&b[i]);
	}
	
	/* ~~~~~~~~~~~~~~~ Taking Values of B in C ~~~~~~~~~~~~~~~~~ */
	for(i=1;i<=n;i++)
		c[i]=b[i];
		
	/* ~~~~~~~~~~~~~~~~ Augmented Matrix ~~~~~~~~~~~~~~~~~~~~~~~ */
	printf("\n\n We need to Solve Ax=b where : \n");
	
	for(i=1;i<=n;i++){
		printf("\n[\t");
		for(j=1;j<=n;j++)
			printf("%f\t",a[i][j]);
		printf("|\t %f \t]",b[i]);
	}
	printf("\n\n");

	/* ~~~~~~~~~~~~~~ Gauss Elimination ~~~~~~~~~~~~~~~~~~~~~~~ */
	for(k=1;k<=n;k++){
		for(i=k+1;i<=n;i++){
		
			if(a[k][k] == 0){
				for(p=k+1;p<=n;p++)
					if(a[p][k] != 0)
						index=p;
				for(p=1;p<=n;p++){
					temp=a[index][p];
					a[index][p]=a[k][p];
					a[k][p]=temp;
				}
			}

			multipliers[i][k]= a[i][k]/a[k][k];
			multiplier=multipliers[i][k];
		
			for(j=1;j<=n;j++){
				a[i][j]=a[i][j]-(multiplier*a[k][j]);
			}
			b[i]=b[i]-(multiplier*b[k]);		
			
		}	
	}
	/* ~~~~~~~~~~~~ Defining Matrix U ~~~~~~~~~~~~~ */	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			u[i][j]=a[i][j];

	/* ~~~~~~~ Defining and Printing Matrix L ~~~~~ */
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)
				l[i][j]=1;
			else if(j>i)
				l[i][j]=0;
			else
				l[i][j]=multipliers[i][j];
		}
	}	

	printf("\n\n The Matrix L is : \n");
	for(i=1;i<=n;i++){
		printf("\n[\t");
		for(j=1;j<=n;j++)
			printf("%f\t",l[i][j]);
		printf("]");
	}
	printf("\n\n");

	/* ~~~~~~~~~~~~~~~~~~ Matrix U ~~~~~~~~~~~~~~~~ */
	printf("\n\n The Matrix U is : \n");
	for(i=1;i<=n;i++){
		printf("\n[\t");
		for(j=1;j<=n;j++)
			printf("%f\t",u[i][j]);
		printf("]");
	}
	printf("\n\n");

	/* ~~~~~~~~~~~~~~~ Solving for Y ~~~~~~~~~~~~~ */
	y[1]= (b[1])/(l[1][1]);
	
	for(i=2;i<=n;i++){
		sum=0;
		for(j=1;j<i;j++)
			sum = sum + ( l[i][j] * y[j]);
		y[i]= ( c[i] - sum )/(l[i][i]);	
	}
	
	printf("\n\n The Matrix Y is : \n ");
	for(i=1;i<=n;i++)
		printf(" [ \t %f \t ]\n ",y[i]);
	

	/* ~~~~~~~~~~~~~~ Solving for Roots ~~~~~~~~~~ */
	root[n]= (y[n])/(u[n][n]);
	for(k=n-1;k>=1;k--){
		sum=0;
		for(j=k+1;j<=n;j++)
			sum= sum + ( u[k][j]*root[j] );
		root[k] = (y[k] - sum)/(u[k][k]);
	}
	for(k=1;k<=n;k++)
		printf("\n\n x[%d] = %f ",k,root[k]);
	printf("\n\n");

}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Please enter the number of variables : 3

 Enter the coefficients of the variables in this equation :
1 2 1

Enter the Constant in the equation : 
0

 Enter the coefficients of the variables in this equation :
2 2 3

Enter the Constant in the equation : 
3

 Enter the coefficients of the variables in this equation :
-1 -3 0

Enter the Constant in the equation : 
2


 We need to Solve Ax=b where : 

[	1.000000	2.000000	1.000000	|	 0.000000 	]
[	2.000000	2.000000	3.000000	|	 3.000000 	]
[	-1.000000	-3.000000	0.000000	|	 2.000000 	]



 The Matrix L is : 

[	1.000000	0.000000	0.000000	]
[	2.000000	1.000000	0.000000	]
[	-1.000000	0.500000	1.000000	]



 The Matrix U is : 

[	1.000000	2.000000	1.000000	]
[	0.000000	-2.000000	1.000000	]
[	0.000000	0.000000	0.500000	]



 The Matrix Y is : 
  [ 	 0.000000 	 ]
  [ 	 3.000000 	 ]
  [ 	 0.500000 	 ]
 

 x[1] = 1.000000 

 x[2] = -1.000000 

 x[3] = 1.000000 
*/
