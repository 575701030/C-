#include<stdio.h>

float f( float x,float y)
{
	return -x*x*y*y*y;
}

void Runge_Kutta( float a,float b,int n )
{
	int i;
	float x[30],y[30],h;
	float k1,k2,k3,k4;
	y[0]=1,x[0]=a;				//初值
	printf("x[0]=%f\ty[0]=%f\n",x[0],y[0]);	
	h=(b-a)/n;
	for( i=0; i<n; i++ )
	{
		x[i+1]=a+h*(i+1);
		k1=f( x[i],y[i] );
		k2=f( x[i]+h/2,y[i]+h*k1/2 );
		k3=f( x[i]+h/2,y[i]+h*k2/2 );
		k4=f( x[i]+h,y[i]+h*k3 );
		y[i+1]=y[i]+h/6*(k1+2*k2+2*k3+k4);
		printf("x[%d]=%f\ty[%d]=%f\n",i+1,x[i+1],i+1,y[i+1]);
	}
}

int main()
{
	int n=20;				//n为等分数 
	float a=0,b=5;			//a为下边界，b为上边界
	Runge_Kutta( a,b,n );
	return 0;
 } 
