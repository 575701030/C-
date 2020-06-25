/*˳�������*/
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
	printf("�������ɸ��������ݣ�����˳�������-1��������");
	scanf("%d",&x);
	while(x!=-1)
	{
		i++;
		if(!Insert(L,x,i))exit(0);
		scanf("%d",&x); 
	}
	printf("����ǰ��");
	PrintList(L);
	Invert(L);
	printf("���ú�"); 
	PrintList(L); 
}

sequenlist*InitList()
//������˳���
 {
 	sequenlist*L=(sequenlist*)malloc(sizeof(sequenlist));
 	L->last=0;
 	return L;
 }

int Length(sequenlist*L)
//�����
{
	return L->last;
}

int Insert(sequenlist*L,datatype x,int i)
//���½�����˳���ĵ�i��λ��
{
	int j;
	if(L->last>=maxsize-1)
	{
		printf("������");
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
//���˳��� 
{
	int i;
	for(i=1;i<=(L->last);i++)
	printf("%5d",L->data[i]);
	printf("\n");
}

void Invert(sequenlist*L)
//����˳��� 
{
	int i,r;
	for(i=1;i<=(L->last)/2;i++)
	{
		r=L->data[i];
		L->data[i]=L->data[(L->last-i+1)];
		L->data[(L->last-i+1)]=r;
	}
}
