#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024

typedef char datatype;
typedef struct node{
	datatype data;
	struct node *lchild,*rchild;
}bitree;
bitree *root;

bitree *CREATREE()//建立二叉树 
{char ch;
bitree *q[maxsize];
int front,rear;
bitree *root,*s;
root=NULL;
front=1;rear=0;
while((ch=getchar())!='#')
{s=NULL;
if(ch!='@')
{s=(bitree*)malloc(sizeof(bitree));
s->data=ch;
s->lchild=NULL;
s->rchild=NULL;
}
rear++;
q[rear]=s;
if(rear==1) root=s;
else{if(s&&q[front])
if(rear%2==0)q[front]->lchild=s;
else q[front]->rchild=s;
if(rear%2==1)front++;
}
}return root;
}

void preorder(bitree *p)//先序遍历输出 
{
	if(p!=NULL)
	{printf("%c",p->data);
	preorder(p->lchild);
	preorder(p->rchild);
	}
}

void inorder(bitree *p)//中序遍历输出 
{
	if(p!=NULL)
	{inorder(p->lchild);
	printf("%c",p->data);
	inorder(p->rchild);
	}
}

void exchange(bitree*p)//交换左右子树 
{
	bitree *f;
	if(p!=NULL)
	{
		f=p->lchild;
		p->lchild=p->rchild;
		p->rchild=f;
		exchange(p->lchild);
		exchange(p->rchild);
	}
}

main()
{
	bitree*T;
	T=CREATREE();
	preorder(T);
	printf("  ");
	inorder(T);
	printf("\n");
	exchange(T);
	preorder(T);
	printf("  ");
	inorder(T);
}












