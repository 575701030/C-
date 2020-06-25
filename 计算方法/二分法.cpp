#include<stdio.h>
#include<math.h>
#define x_error 5e-6      //为x允许误差
#define f_error 1e-6      //为f(x)允许误差

float f( float x )
{
	float result;
	result=pow( x,3 ) + 4*pow( x,2 )-10;
	return result;
}
 
int main()
{
	int i;
	float limit_down,limit_up,x,mid; 
	limit_down=1,limit_up=2;
	for( i=1; ;i++ )
	{
		if( f( limit_down )*f( limit_up )>0 )
		{
			printf("不能用二分法求解。");
			break; 
		}	
		mid=( limit_down+limit_up )/2;
		printf("i=%2d   x=%f   f(c)=%f\n",i,mid,f(mid));
		if( mid-limit_down < x_error ) break;
		if( fabs( f(mid) ) < f_error ) break;
		if( f( limit_down )*f( mid )>0 )
		{
			limit_down=mid;
		}
		else
		{
			limit_up=mid;
		}
	}
	printf("方程的根为%f",mid);
	return 0;
}
