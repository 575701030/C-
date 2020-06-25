#include<stdio.h>

void DirectLU(float *u,int n,float x[])
{
	int i,r,k;
	for(r=0;r<=n-1;r++)
	{
		for(i=r;i<=n;i++)
		for(k=0;k<=r-1;k++)
		*(u+r*(n+1)+i)-=*(u+r*(n+1)+k)*(*(u+k*(n+1)+i));
		for(i=r+1;i<=n-1;i++)
		{
			for(k=0;k<=r-1;k++)
			*(u+i*(n+1)+r)-=*(u+i*(n+1)+k)*(*(u+k*(n+1)+r));
			*(u+i*(n+1)+r)/=*(u+r*(n+1)+r);
		}
	}
	for(i=n-1;i>=0;i--)
	{
		for(r=n-1;r>=i+1;r--)
		*(u+i*(n+1)+n)-=*(u+i*(n+1)+r)*x[r];
		x[i]=*(u+i*(n+1)+n)/(*(u+i*(n+1)+i));
	}
}

main()
{
	float x[4];
	int i;
	float a[4][5]={1,2,-12,8,27,
	5,4,7,-2,4,
	-3,7,9,5,11,
	6,-12,-8,3,49};
	DirectLU(a[0],4,x);
	for(i=0;i<=3;i++)
	printf("x[%d]=%f\n",i,x[i]);
}
