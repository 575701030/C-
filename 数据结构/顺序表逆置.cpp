/*顺序表逆置*/
#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int last;
} 
sequenlist;
//
sequenlist*InitList();
int Length(sequenlist*);
int Insert(sequenlist*,datatype,int);
void PrintList(sequenlist*);
void Invert(sequenlist*);
//
main()
{
	sequenlist*L;
	int i=0;
	datatype x;
	L=InitList();
	printf("输入若干个整型数据，建立顺序表（输入-1结束）；");
	scanf("%d",&x);
	while(x!=-1)
	{
		i++;
		if(!Insert(L,x,i))exit(0);
		scanf("%d",&x); 
	}
	printf("逆置前：");
	PrintList(L);
	Invert(L);
	printf("逆置后："); 
	PrintList(L); 
}

sequenlist*InitList()
//建立空顺序表
 {
 	sequenlist*L=(sequenlist*)malloc(sizeof(sequenlist));
 	L->last=0;
 	return L;
 }

int Length(sequenlist*L)
//求表长度
{
	return L->last;
}

int Insert(sequenlist*L,datatype x,int i)
//将新结点插入顺序表的第i个位置
{
	int j;
	if(L->last>=maxsize-1)
	{
		printf("表已满");
		return 0;
	}
	else
	{
		for(j=L->last;j>=i;j--)
		L->data[j+1]=L->data[j];
		L->data[i]=x;
		L->last++;
		return 1;
	}
} 

void PrintList(sequenlist*L)
//输出顺序表 
{
	int i;
	for(i=1;i<=(L->last);i++)
	printf("%5d",L->data[i]);
	printf("\n");
}

void Invert(sequenlist*L)
//逆置顺序表 
{
	int i,r;
	for(i=1;i<=(L->last)/2;i++)
	{
		r=L->data[i];
		L->data[i]=L->data[(L->last-i+1)];
		L->data[(L->last-i+1)]=r;
	}
}
