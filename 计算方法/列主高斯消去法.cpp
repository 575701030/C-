#include<stdio.h>
#include<math.h>

int main()
{
	int k,i,j,n=3,max_hang;   //nÎª½×Êý 
	float max,he=0;
	float buf[5],l[5],x[5];
	float a[4][5]={
						0,0,0,0,0,
						0,2,4,1,4,
						0,2,6,-1,10,
						0,1,5,2,2
					};
	for( k=1; k<=n-1 ;k++ )
	{
		max=a[k][k];               
		for( i=k; i<=n ; i++ )
		{
			if( fabs( a[i][k] ) > fabs( max ) )
			{
				max=a[i][k];
				max_hang=i;
			}
			if( max==a[k][k] )
			{
				max_hang=k;
			}
		}
		if( max==0 ) 	break;
		else
		{
			if( max_hang!=k )
			{
				for( j=k; j<=n+1; j++ )
				{
					buf[j]=a[max_hang][j];
					a[max_hang][j]=a[k][j];
					a[k][j]=buf[j];
				}
			}
			for( i=k+1; i<=n ; i++ )
			{
				l[i]=a[i][k]/a[k][k];
				for( j=k; j<=n+1; j++ )
				{
					a[i][j]=a[i][j]-l[i]*a[k][j];
				}
			}
		}
	}
	if( a[n][n]==0 )
	{
		printf("¾ØÕóÆæÒì"); 
	}
	else
	{
		x[n]=a[n][n+1]/a[n][n];
		for( i=n-1; i>=1; i-- )
		{
			for( j=i+1; j<=n; j++ )
			{
				he=he+a[i][j]*x[j];
			}
			x[i]=( a[i][n+1]-he )/a[i][i];
			he=0;
		}
		for( i=1; i<=n; i++ )
		{
			printf("x[%d]=%f\n",i,x[i]);
		}
	}
	return 0;
}

