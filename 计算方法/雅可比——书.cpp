#include<stdio.h>
#include<math.h>
#define eps 1e-6
#define max 100

void Jacobi(float *a,int n,float x[])
{
	int i,j,k=0;
	float epsilon,s;
	float *y=new float[n];
	for(i=0;i<n;i++)
	x[i]=0;
	while(1)
	{
		epsilon=0;
		k++;
		for(i=0;i<n;i++)
		{
			s=0;
			for(j=0;j<n;j++)
			{
				if(j==i)
				continue;
				s+=*(a+i*(n+1)+j)*x[j];
			}
			y[i]=(*(a+i*(n+1)+n)-s)/(*(a+i*(n+1)+i));
			epsilon+=fabs(y[i]-x[i]);
		}
		for(i=0;i<n;i++)
		x[i]=y[i];
		if(epsilon<eps)
		{
			printf("迭代次数为%d\n",k);
			return;
		}
		if(k>=max)
		{
			printf("迭代发散");
			return;
		}
	}
	delete y;
}

main()
{
	int i;
	float a[4][5]=
	{4,-1,-1,0,
	 1,-1,4,0,
	 -1,2,-1,0,
	 4,-1,0,0,
	 -1,-1,4,1};
	 float x[4];
	 Jacobi(a[0],4,x);
	 for(i=0;i<4;i++)
	 printf("x[%d]=%f\n",i,x[i]);
}
