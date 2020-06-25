#include<stdio.h>
#include<math.h>
#define N 100
#define x_error 1e-6      //Ϊx�������
#define f_error 1e-8      //Ϊf(x)�������

float f( float x )        //��ֵ 
{
	float result;
	result=pow( x,3 ) + pow( x,2 )-3*x-3;
	return result;
}

float f_dao( float x )    //�� 
{
	float result;
	result=3*pow( x,2 ) + 2*x-3;
	return result;
}

int main()
{
	int i;
	float x0,x1,y0;
	printf("�����������ֵx0\n");
	scanf("%f",&x0); 
	for ( i=0; ;i++ )
	{
		if( f_dao(x0)==0 || i>N )
		{
			printf("Newton������ɢ\n");
			break;
		}
		x1=x0-f(x0)/f_dao(x0);
		printf("x(%d)=%f\n",i+1,x1);
		if( fabs( x1-x0 ) < x_error || fabs( f(x1) ) < f_error )
		{
			printf("ԭ���̵ĸ�x=%f\n",x1);
			break;
		}
		else
		{
			x0=x1;
		}
	}
	return 0;
}
