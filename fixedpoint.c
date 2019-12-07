/* Problem 3 : Fixed-Point Method
	Anirban Saha
	Roll No. : 001520601011 
*/

#include<stdio.h>
#include<math.h>
#define ERR 0.00001

float function(float x)
{
        float answer;
        answer = x*x - 4*x + 3;
        return answer;
}

float rootf(float x)
{
	float root;
	root=(4*x-3)/x;
	return root;
}

int main()
{
	float root,root1;
	int i=0;
	printf("\n\nPlease enter an initial guess : ");
	scanf("%f",&root);
	printf("\n\n N\t x(n)\t\t  x(n+1)\t|x(n+1)-x(n)|");

	do{
		root1=rootf(root);
		printf("\n %d\t %f\t %f\t %f",i,root,root1,fabs(root-root1));
		if(fabs(root1-root) < ERR )
			break;
		i++;
		root=root1;
	}while(1);
	printf("\n\n The Root correct upto 4 decimal places is %10.4f\n\n",root);
	return 0;
}

/* 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OUTPUT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter an initial guess : 5


 N	 x(n)		  x(n+1)	|x(n+1)-x(n)|
 0	 5.000000	 3.400000	 1.600000
 1	 3.400000	 3.117647	 0.282353
 2	 3.117647	 3.037736	 0.079911
 3	 3.037736	 3.012422	 0.025314
 4	 3.012422	 3.004124	 0.008299
 5	 3.004124	 3.001373	 0.002751
 6	 3.001373	 3.000457	 0.000915
 7	 3.000457	 3.000152	 0.000305
 8	 3.000152	 3.000051	 0.000102
 9	 3.000051	 3.000017	 0.000034
 10	 3.000017	 3.000006	 0.000011
 11	 3.000006	 3.000002	 0.000004

 The Root correct upto 4 decimal places is     3.0000

*/

		
