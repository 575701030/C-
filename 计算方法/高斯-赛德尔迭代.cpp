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
	float x1_last,x2_last,x3_last,x4_last;
	int k;
	for( k=1;  ;k++ )
	{
		x1_last=x1;
		x1=f1( x2,x3 );
		x2_last=x2;
		x2=f2( x1,x4 );
		x3_last=x3;
		x3=f3( x1,x4 );
		x4_last=x4;
		x4=f4( x2,x3 );
		float error1=fabs( x1-x1_last ),error2=fabs( x2-x2_last ),error3=fabs( x3-x3_last ),error4=fabs( x4-x4_last );
		printf("k=%2d   x1=%f   x2=%f   x3=%f   x4=%f\n",k,x1_last,x2_last,x3_last,x4_last);
		if( fabs( x1-x1_last )<x_error && fabs( x2-x2_last )<x_error && fabs( x3-x3_last )<x_error && fabs( x4-x4_last )<x_error || k>max )
		{
			break;
		}
	}
	return 0;
}
