/* Anirban Saha
   Class Roll : 001520601011
   Problem 13 : Find The Solution Of a System of Linear Equations using Gauss-Seidel Method
*/

#include<stdio.h>
#include<math.h>
#define ERR 0.00001


int main()
{
	float a[15][15],b[15],root[15],x[15],sum,temp;
	int i,j,n,m,k=1,e,f,swap_index;
	printf("\n\nPlease enter the number of variables : ");
	scanf("%d",&n);
	

	for(i=1;i<=n;i++){
		printf("\n Enter the coefficients of the variables in this equation :\n");
		for(j=1;j<=n;j++)
			scanf("%f",&a[i][j]);
		printf("\nEnter the Constant in the equation : \n");
		scanf("%f",&b[i]);
	}
	
	printf("\n\n We need to Solve Ax=b where : \n");
	
	for(i=1;i<=n;i++){
		printf("\n[\t");
		for(j=1;j<=n;j++)
			printf("%f\t",a[i][j]);
		printf("|\t %f \t]",b[i]);
	}

	printf("\n\n");



	for(i=1;i<=n;i++)
		root[i]=0;



	while(1){
		m=0;	
		for(i=1;i<=n;i++){


			if(a[i][i]==0){
				for(e=i+1;e<=n;e++)
					if(a[e][i]!=0)
						swap_index=e;
				for(f=1;f<=n;f++){
					temp=a[swap_index][f];
					a[swap_index][f]=a[i][f];
					a[i][f]=temp;
				}
			}					

				
			sum=0;
			for(j=1;j<=n;j++)
				if(j != i)
					sum = sum + ( a[i][j]*root[j] );
			root[i]= ( b[i] - sum )/a[i][i];
			
			printf("\n root[%d]^(%d) = %f ",i,k,root[i]);
						
			if(fabs((root[i]-x[i])<ERR) && (k>1))
				m++;
			x[i]=root[i];
		}
		
		if(m==n)
			break;
		k++;
	}


	printf("\n The Root is : \n");
	for(i=1;i<=n;i++)
			printf("x[%d] = %.4f \n",i,root[i]);
	return 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Please enter the number of variables : 3

 Enter the coefficients of the variables in this equation :
10 3 1

Enter the Constant in the equation : 
14

 Enter the coefficients of the variables in this equation :
2 -10 3

Enter the Constant in the equation : 
-5

 Enter the coefficients of the variables in this equation :
1 3 10

Enter the Constant in the equation : 
14


 We need to Solve Ax=b where : 

[	10.000000	3.000000	1.000000	|	 14.000000 	]
[	2.000000	-10.000000	3.000000	|	 -5.000000 	]
[	1.000000	3.000000	10.000000	|	 14.000000 	]


 root[1]^(1) = 1.400000 
 root[2]^(1) = 0.780000 
 root[3]^(1) = 1.026000 
 root[1]^(2) = 1.063400 
 root[2]^(2) = 1.020480 
 root[3]^(2) = 0.987516 
 root[1]^(3) = 0.995104 
 root[2]^(3) = 0.995276 
 root[3]^(3) = 1.001907 
 root[1]^(4) = 1.001227 
 root[2]^(4) = 1.000817 
 root[3]^(4) = 0.999632 
 root[1]^(5) = 0.999792 
 root[2]^(5) = 0.999848 
 root[3]^(5) = 1.000067 
 root[1]^(6) = 1.000039 
 root[2]^(6) = 1.000028 
 root[3]^(6) = 0.999988 
 root[1]^(7) = 0.999993 
 root[2]^(7) = 0.999995 
 root[3]^(7) = 1.000002 
 root[1]^(8) = 1.000001 
 root[2]^(8) = 1.000001 
 root[3]^(8) = 1.000000 
 The Root is : 
x[1] = 1.0000 
x[2] = 1.0000 
x[3] = 1.0000 
*/
