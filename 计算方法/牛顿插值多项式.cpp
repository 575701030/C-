#include<stdio.h>
#define N 5

int main()
{
	int i,k,m;
	float b1=0,b2=0,varx1=0.1581,varx2=0.636,ans=1;
	float x[N+1]={0.125,0.250,0.375,0.500,0.675,0.750};
	float y[N+1]={0.79618,0.77334,0.74371,0.70413,0.65632,0.60228};
	float f[6]={0,0,0,0,0,0};
	float xx[6]={1,1,1,1,1,1},xx1[6]={1,1,1,1,1,1};
	float add1=0,add2=0;
	for( k=0; k<=4; k++ )
	{
		for( m=0; m<=k; m++ )
		{
			for( i=0; i<=k; i++ )
			{
				if( i!=m )
				{
					ans=ans*( x[m]-x[i] );
				}
			}
			f[k]=f[k]+y[m]/ans;
			ans=1;
		}
	}
	for( i=0; i<=5; i++ )
	{
		for( k=0; k<i; k++ )
		{
			xx[i]=xx[i]*( varx1-x[k] );
		}	
	}
	for( i=0; i<=5; i++ )
	{
		for( k=0; k<i; k++ )
		{
			xx1[i]=xx1[i]*( varx2-x[k] );
		}	
	}
	for( i=0; i<=5; i++ )
	{
		add1=add1+f[i]*xx[i];
		add2=add2+f[i]*xx1[i];
	}
	printf("N(0.1581)=%f\nN(0.636)=%f",add1,add2);
	return 0;
}
