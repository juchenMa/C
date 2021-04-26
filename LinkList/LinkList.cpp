#include <stdio.h>
#include <stdlib.h>
/*
单链表的建立(带头节点): 
1.头插法
2.尾插法
3，按序插入
4.按位删除
5.按节点删除
6.按位查找
7.按值查找
*/
//把结构体LNode 声明为LNode和*LinkList这两个名字,后面为指针的名字
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;//*为指向struct LNode类型的指针 称为LinkList

//带头节点的初始化
/*****&表示不是复制 就是位于内存中的该份数据,是引用******/
bool InitListwithHN(LinkList &L){
    //头节点不储存数据
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    return true;
}
//带头节点头插操作
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
//带头节点尾插操作
bool InsertNextNode(LNode *p,int e){
    if (p==NULL)
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s-> data=e;
    s->next= p->next;
    p->next=s;
    return true; 
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
//带头节点按位删除
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
//带头节点按节点删除
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
//带头节点按位查找
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
//带头节点按值查找 返回节点
LNode * GetValue(LinkList L, int e){
    LNode *p=L->next;
    while(p->data != e && p != NULL){
        p=p->next;
    }
    return p;
}






/*
1.不带头节点的初始化
2.不带头节点的按序插入     
*/
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