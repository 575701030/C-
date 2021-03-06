#include<stdio.h>                            //头文件 
#include<stdlib.h>


typedef int datatype;                        //定义单链表数据类型 
typedef struct node
{
	datatype data;                           //数值域 
	struct node*next;                        //指针域 
}linklist;                 


   void Insert(linklist*head,int a)          //单链表头插数值    已知(头结点,插入值) 
{
	linklist*p=head,*s;                      //p指向头结点 
	s=(linklist*)malloc(sizeof(linklist));   //建立新节点 
	s->data=a;                               //给新节点赋值 
	s->next=p->next;                         //新节点指向第一个节点 
	p->next=s;                               //头结点指向新节点 
}


linklist*Locate(linklist*head,datatype key)  //在一个链表中找相同值 ，返回其地址    已知(头结点,查找值(整形)) 
{
	linklist*p=head->next;                   //P指向第一个指针 
	while(p!=NULL&&p->data!=key)             //遍历整个链表(直到为NULL或找到） 
	p=p->next;
	if(p==NULL) return NULL;                 //查找不到，返回NULL 
	else return p;                           //查找到返回其地址 
}


linklist*CreateListF()                       //建立链表    带头节点的头插法，返回单链表的头指针（去除重复数） 
{
	linklist*head; int a;                    //声明插入数值类型 
	head=(linklist*)malloc(sizeof(linklist));//建立头结点 
	head->next=NULL;                         //令头结点指针域为空 
	scanf("%d",&a);                          //输入第一个数值 
	while(a!=0)                              //循环插入数值   当输入0结束 
	{
	  if(Locate(head,a)==NULL)Insert(head,a);//插入数值(去除重复数) 
	  scanf("%d",&a);                        //输入下一个数值 
	}
	return head;                             //返回头指针 
} 


linklist*copy(linklist*L)                    //复制链表    返回复制链表头节点   已知（要复制链表） 
{
	linklist*head,*p;
	head=(linklist*)malloc(sizeof(linklist));//建新头节点 
	head->next=NULL;                         //令指针域为NULL 
	p=L->next;                               //p指向第一个节点 
	while(p!=NULL)                           //逐个插入，p指向表尾结束   
	{
		Insert(head,p->data);                 
		p=p->next;
	}
	return head;
}


linklist*Jiao(linklist*L1,linklist*L2)       //求交集,返回头结点     已知（两链表头指针） 
{
	linklist*head,*p,*q,*s;      
	head=(linklist*)malloc(sizeof(linklist));//建立交集头结点 
	head->next=NULL;                         //头结点指针域为空 
	p=L2;                                    //p指向L2头结点 
	q=L1;                                    //q指向L1头结点 
	while(p->next!=NULL)                     //遍历L2链表 
	{
		s=Locate(q,p->next->data);           //在L1中查找L2数值是否存在 
		if(s!=NULL) Insert(head,s->data);    //如果存在插入交集链表 
		p=p->next;                           //P指向L2下一个节点 
	}
	return head;                             //返回交集头指针 
} 


linklist*Locate2(linklist*head,datatype key) //在一个链表中找相同值 ，返回此值上一地址        已知(头结点,查找值) 
{
	linklist*p=head;                         //p指向头结点 
	while(p->next!=NULL&&p->next->data!=key) //遍历整个链表直到为NULL或使P的下一节点数值为查找值 
	p=p->next;                 
	if(p->next==NULL) return NULL;           //未找到返回NULL 
	else return p;                           //找到则返回p的地址 
}


void Delete(linklist*p)                      //删除单链表中的值   已知（删除值的上一节点） 
{
	linklist*r;
	r=p->next;                               //r指向删除节点 
	p->next=r->next;                         //使删除节点的上一节点指向删除节点的后一节点 
	free(r);                                 //释放删除节点存储空间 
}


linklist*Cha(linklist*L1,linklist*L3)        //求差集(L1-L2)   返回头结点    已知（L1链表头结点，L1,L2交集头结点） 
{
	linklist*head,*p,*q,*s;
	head=copy(L1);                           //令head为L1复制链表头指针 
	p=L3;                                    //p指向L3头指针   
	q=head;                                  //q指向head
	while(p->next!=NULL)                     //b遍历L3 
	{ 
		s=Locate2(q,p->next->data);          //查找在L1复制链表中是否有于L3中相同的值 
	    Delete(s);                           //在L1复制链表中删除两链表的相同数值 
		p=p->next;              
	}
	return head;                             //返回差集链表头指针 
 } 
 
 
linklist*Bing(linklist*L2,linklist*L4)       //求并集  返回头结点    已知（L2头结点，L1-L2差集头结点） 
{
	linklist*head,*p,*q;
	head=copy(L2);                           //令head指向L2复制链表头指针 
	p=head;                                  //p指向L2复制链表头指针
	q=L4;                                    //q指向L4头指针
	while(q->next!=NULL)                     //遍历L4 
	{
		Insert(p,q->next->data);             //把差集中数据插入L2复制链表中 
		q=q->next;               
	}
	return head;                             //返回并集头指针 
}


void Print(linklist*head)                    //输出单链表   已知（输出链表头指针） 
{
	linklist*temp;
	temp=head->next;                         //令temp指向第一个节点 
	while(temp!=NULL)                        //遍历链表 
	{
	    printf("%3d",temp->data);            //输出数值 
	    temp=temp->next;
	}
	printf("\n");
} 


int main()
{
	linklist*L1,*L2,*L3,*L4,*L5;
	printf("输入L1(输入0结束)：");
	L1=CreateListF();                         //建立单链表LI 
	printf("L1：");
	Print(L1); 
	printf("输入L2(输入0结束)："); 
	L2=CreateListF();	                      //建立单链表LI
	printf("L2：");
	Print(L2);
    L3=Jiao(L1,L2);                           //求交集 
    printf("交集：");
	Print(L3);  
    L4=Cha(L1,L3);                            //求差集 
    printf("差集(L1-L2)：");
	Print(L4);
	L5=Bing(L2,L4);                           //求并集 
	printf("并集：");  
	Print(L5);
	return 0;
}
