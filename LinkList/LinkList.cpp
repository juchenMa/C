#include <stdio.h>
#include <stdlib.h>
/*
单链表的插入：
1.按序插入：
    1).带头节点
    2).不带头节点
2.指定节点前插
3.指定节 点后插
*/

/*
单链表删除(带头节点)：
1.按序删除
2.按节点删除
*/

/*
单链表查找(带头节点)：
1. 按位查找
2. 按值查找
*/

/*
单链表的建立(带头节点): 对应插入的两种方法
1.尾插法
2.头插法
*/

//把结构体LNode 声明为LNode和*LinkList这两个名字,后面为指针的名字
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;//*为指向struct LNode类型的指针 称为LinkList

//前插操作
/*不给出头节点，无法得到之前节点的信息，采用交换数据的方法来实现*/
bool InsertPriorNode(LNode *p,int e){
    if (p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if (s==NULL){
        return false;
    }   
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

//后插操作
bool InsertNextNode(LNode *p,int e){
    if (p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s-> data=e;
    s->next= p->next;
    p->next=s;
    return true; 
}

//按位删除
bool ListDelete(LinkList &L, int i, int e){
    if (i<1)
        return false;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i-1){
        //->左边为指针 功能与. 相同
        p=p->next;
        j++;
    }
    if (p==NULL)
        return false;
    if(p->next==NULL){
        return false;
    }
    LNode *q=p->next;
    e=q->data;
    p->next = q->next;
    free(q);
    return true;
}

//按节点删除
bool DeleteNode(LNode *p){
    if (p== NULL){
        return false;
    }
    //如果p->next为空，p为最后一个节点的时候，使用该方法无法删除；
    if (p->next==NULL){
        return false;
    }
    p->data=p->next->data;
    p->next=p->next->next;
    free(p->next);
    return true;
}
//按位查找，带头节点
LNode * GetElem(LinkList L, int i){
    //i==0 为头节点
    if (i<0){
        return NULL;}
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i-1){
        //->左边为指针 功能与. 相同
        p=p->next;
        j++;
    }
    return p;
}
//按值查找 返回节点
LNode * GetValue(LinkList L, int e){
    LNode *p=L->next;
    while(p->data != e && p != NULL){
        p=p->next;
    }
    return p;
}
// 求链表的长度 不算头节点
int length(LinkList L){
    int len=0;
    LNode *p=L->next;
    while(p != NULL){
        len++;
        p = p->next;
    }
    return len;
}
//建立链表，尾插法
//加入一千个节点
LinkList List_TailInit(LinkList &L){
    int x=0;
    LNode *s=(LinkList)malloc(sizeof(LNode));
    LNode *r = L;
    while (x!=1000){
        s->data=x;
        s->next=r->next;
        r->next=s;
        r=s;
        //InsertNextNode(r,x);
        //r=r->next;
        x++;
    }
    return L;
}
//带头节点的初始化
/*****&表示不是复制 就是位于内存中的该份数据,是引用******/
bool InitListwithHN(LinkList &L){
    //为头节点分配空间
    //头节点不储存数据
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}
bool Empty(LinkList L){
    return (L==NULL);
}
//带头节点的按序插入
bool ListInsertwithHN(LinkList &L, int i, int e){
    if (i<1)
        return false;
    LNode *p;
    int j=0; 
    p=L;
    while(p!=NULL && j<i-1){
        //->左边为指针 功能与. 相同
        p=p->next;
        j++;
    }
    return InsertNextNode(p, e);
}


//不带头节点的初始化
bool InitListwithoutHN(LinkList &L){
    L = NULL;           
    return true;
}
//不带头节点的按序插入      
/*需要对第一个节点进行特殊操作*/
bool ListInsertwithoutHN(LinkList &L, int i, int e){
    if (i<1)
        return false;
    if (i==1){
        //分配新的空间 
        LNode *s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        //L当前为空
        s->next=L;
        L=s;
        return true;
    }
    LNode *p;
    int j=1;
    p=L;
    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

int main(){
    LinkList L;
    //L为头指针
    InitListwithHN(L);
    List_TailInit(L);
//    for (int i=0; i<length(L);i++){
  //      //printf("%d\n",i);
   //     printf("value is %d\n",GetElem(L,i)->data);
   // }
    printf("value is %d\n",GetElem(L,2)->data);
    
}