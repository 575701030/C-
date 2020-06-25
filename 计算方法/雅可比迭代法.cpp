#include<stdio.h>
#include<math.h>

#define x_error 1e-6      //ÎªxÔÊĞíÎó²î
#define max 100

float f1( float x2, float x3 )
{
	return ( x2+x3+1 )/4;
}

float f2( float x1, float x4 )
{
	return ( x1+x4+2 )/4;
}

float f3( float x1, float x4 )
{
	return (x1+x4)/4;
}

float f4( float x2, float x3 )
{
	return (x2+x3+1)/4;
}

int main()
{
	float x1=0,x2=0,x3=0,x4=0;
	float x1_new,x2_new,x3_new,x4_new;
	int k;
	for( k=1;  ;k++ )
	{
		x1_new=f1( x2,x3 );
		x2_new=f2( x1,x4 );
		x3_new=f3( x1,x4 );	
		x4_new=f4( x2,x3 );
		float error1=fabs( x1-x1_new ),error2=fabs( x2-x2_new ),error3=fabs( x3-x3_new ),error4=fabs( x4-x4_new );
		printf("k=%2d   x1=%f   x2=%f   x3=%f   x4=%f\n",k,x1_new,x2_new,x3_new,x4_new);
		if( fabs( x1_new-x1 )<x_error && fabs( x2_new-x2 )<x_error && fabs( x3_new-x3 )<x_error && fabs( x4_new-x4 )<x_error || k>max )
		{
			break;
		}
		x1=x1_new;
		x2=x2_new;
		x3=x3_new;
		x4=x4_new;
	}
	return 0;
}
