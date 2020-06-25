#include<stdio.h>
#include<math.h>


int main()
{
	int n=4; //nÎª½×Êý 
	int i,j,k,q;
	float he=0;
	float x[10],y[10];
	float u[5][5],l[5][5];
	float a[5][6]={
					0,0,0,0,0,0,
					0,1,2,-12,8,27,
					0,5,4,7,-2,4,
					0,-3,7,9,5,11,
					0,6,-12,-8,3,49
					} ;				
	for( j=1; j<=n; j++ )
	{
		u[1][j]=a[1][j];
	}
	for( i=2; i<=n; i++ )
	{
		l[i][1]=a[i][1]/a[1][1];
	}
	for( k=2; k<=n; k++ )
	{
		for( j=k; j<=n; j++ )
		{
			for( q=1; q<=k-1; q++ )
			{
				he=he+l[k][q]*u[q][i];
			}
			u[k][j]=a[k][j]-he;
		}
		he=0;
		for( i=k+1; i<=n; i++ )
		{
			for( q=1; q<=k-1; q++ )
			{
				he=he+l[i][q]*u[q][k];
			}
			l[i][k]=( a[i][k] - he )/u[k][k];
		}
		he=0;
	}
	y[1]=a[1][n+1];
	for( k=2; k<=n; k++ )
	{
		for( q=1; q<=k-1; q++ )
		{
			he=he+l[k][q]*y[q];
		}
		y[k]=a[k][n+1]-he;
	}
	he=0;
	x[n]=y[n]/u[n][n];
	for( k=n-1; k>=1; k-- )
	{
		for( q=k+1; q<=n; q++ )
		{
			he=he+u[k][q]*x[q];
		}
		x[k]=( y[k]-he )/u[k][k];
	}
	for( i=1; i<=4; i++ )
	{
		printf("x[%d]=%f\n",i,x[i]);
	}
	return 0;
 } 
 
 
 
 
 
 
