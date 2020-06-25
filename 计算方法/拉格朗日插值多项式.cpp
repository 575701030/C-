#include<stdio.h>

int main()
{
	float x[4]={0.46,0.47,0.48,0.49};
	float y[4]={0.484655,0.493745,0.502750,0.511668};
	float xx=0.482515
	;
	float yy=0,mul=1;
	int i,j,n=3;
	for( i=0; i<=n; i++ )
	{
		for( j=0; j<=n ; j++ )
		{
			if( i==j ) continue;
			else
			{
				mul=mul*( xx-x[j] )/( x[i]-x[j] ); 
			}
		}
		yy=yy+mul*y[i];
		mul=1;
	}
	printf("x=%f  y=%f",xx,yy);
	return 0;
}
