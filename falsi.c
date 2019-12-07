/* Problem 2 : Regular Falsi Method
	Anirban Saha
	Roll No. : 001520601011 
*/

#include<stdio.h>
#include<math.h>
#define ERR 0.00001

float function(float x)
{
        float answer;
        answer = x*x*x - 4*x*x + 6*x -  7;
        return answer;
}

float root(float a,float b)
{
	float root;
	root = a - ( ( (b-a) / ( function(b)-function(a) ) )* function(a) );
	return root;
}


int main()
{
	float a,b,mid,mid1,current;
	int i=0;

    printf("\n\nPlease enter value of extreme ends of the Interval : ");
    scanf("%f%f",&a,&b);

	printf("\nn    a(n)\tb(n)\t  x(n))\t     f(a(n))\t  f(b(n))    f(x(n))    |x(n+1)-x(n)|\n");
	
	while(function(a)*function(b)<0 ){
		mid1=mid;
		mid= root(a,b);
		printf("\n%d   %f  %f   %f   %f   %f   %f     %f\n",i,a,b,mid,function(a),function(b),function(mid),fabs(a-b));

		
		i++;
        if( function(a)*function(mid) <= 0)
			b=mid;

	if( function(mid)*function(b) <= 0)
			a=mid;
	current= function(mid);
					
	if( fabs(mid1-mid) < ERR )	
		break;

	}
	printf("\n\n The Root correct upto 4 decimal places is %f\n\n",mid);
	return 0;
}


/*
-----------------------OUTPUT---------------------------------------


Please enter value of extreme ends of the Interval : 2 3

n     a(n)	   b(n)	       x(n))	  f(a(n))   f(b(n))     f(x(n))   |x(n+1)-x(n)|

0   2.000000  3.000000   2.600000   -3.000000   2.000000   -0.864000     1.000000

1   2.600000  3.000000   2.720670   -0.864000   2.000000   -0.145636     0.400000

2   2.720670  3.000000   2.739630   -0.145636   2.000000   -0.022019     0.279330

3   2.739630  3.000000   2.742465   -0.022019   2.000000   -0.003273     0.260370

4   2.742465  3.000000   2.742886   -0.003273   2.000000   -0.000485     0.257535

5   2.742886  3.000000   2.742948   -0.000485   2.000000   -0.000072     0.257114

6   2.742948  3.000000   2.742958   -0.000072   2.000000   -0.000011     0.257052


 The Root correct upto 4 decimal places is 2.742958

*/

