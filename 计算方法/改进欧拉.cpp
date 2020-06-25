#include<stdio.h>
#include<math.h>

float f( float x,float y)
{
	return -x*x*y*y*y;
}

void up_oula( float a,float b,int n )
{
	int i;
	float x[100],y[100],h;
	float yp,yc;
	y[0]=1,x[0]=a;				//初值
	printf("x[0]=%f\ty[0]=%f\n",x[0],y[0]);	
	h=(b-a)/n;
	for( i=0; i<n; i++ )
	{
		x[i+1]=a+h*(i+1);
		yp=y[i]+h*f( x[i],y[i] );
		yc=y[i]+h*f( x[i+1],yp );
		y[i+1]=0.5*( yc+yp );
		printf("x[%d]=%f\ty[%d]=%f\n",i+1,x[i+1],i+1,y[i+1]);
	}
}

int main()

{
	int n=20;				//n为等分数 
	float a=0,b=5;			//a为下边界，b为上边界
	up_oula( a,b,n );
	return 0;
}
