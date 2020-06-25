#include<stdio.h>
#include<math.h>
#define e exp(1)

double f( double x )
{
	return pow(x,3)-2*x-5;
}

int main()
{
	double x[30];
	int i;
	x[0]=2,x[1]=2.2;
	for( i=2; i<30; i++ )
	{
		x[i]=x[i-1]-f( x[i-1] )*( x[i-1]-x[i-2] )/( f( x[i-1] )-f( x[i-2] ) );
		printf( "%d%10f--%f--%f\n",i,x[i],( x[i-1]-x[i] ),f(x[i]) );
		if( fabs( x[i-1]-x[i] )<0.00005 ) break;
	}
	
	
	
//	x[0]=3;
//	for( i=1; i<30; i++ )
//	{
//		x[i]=log( 4*x[i-1] );
//		printf( "%d--%f--%f\n",i,x[i],( x[i-1]-x[i] ) );
//		if( ( x[i-1]-x[i] ) <0.00005 ) break;
//	}



//	x[0]=1; 
//	for( i=1; i<30; i++ )
//	{
//		x[i]=exp( x[i-1] )/4;
//		printf( "%f %f\n",x[i],( x[i-1]-x[i] )*(e)/(4-e) );
//		if( ( x[i-1]-x[i] )*(e)/(4-e) <0.00005 ) break;
//	}
	return 0;
 } 
