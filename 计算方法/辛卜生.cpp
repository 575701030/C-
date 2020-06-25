#include<stdio.h>
#include<math.h>

float f( float x )
{
	return 1/sqrt(x*x*x+1);
}

float S( float a,float b,int n )
{
	int k;
	float h,s1,s2;
	h=(b-a)/n;
	s1=f(a+h/2);
	s2=0;
	for( k=1; k<n; k++ )
	{
		s1=s1+f(a+k*h+h/2);
		s2=s2+f(a+k*h);
	}
	return h/6*( f(a)+4*s1+2*s2+f(b) );
}

int main()
{
	int i;
	int n=2;		//辛卜生n=2 
	float a=0,b=1;	//a为积分下限   b为积分上限
	float s;
	for( i=0; i<5; i++ )
	{
		s=S( a,b,n );
		printf("s(%d)=%f\n",n,s);
		n=2*n;
	}
	return 0;
}
