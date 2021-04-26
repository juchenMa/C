#include <stdio.h>
#include <stdlib.h>

typedef struct LSNode{
    int data;
    struct LSNode *next;
    int top;
}LSNode,*LinkStock;

bool InitStockwithHN(LinkStock &L){
    //为头节点分配空间
    //头节点不储存数据
    L=(LSNode *)malloc(sizeof(LSNode));
    if(L==NULL)
        return false;
    L->next = NULL;
    L.top = 0;
    return true;
}

bool Pop(LinkStock &L,LSNode *p,int e){
    if (p==NULL)
        return false;
    LSNode *s=(LSNode *)malloc(sizeof(LSNode));
    s-> data=e;
    s->next= p->next;
    p->next=s;
    L.top +=1;
    return true; 
}


LNode * GetElem(LinkStock L, int i){
    //i==0 为头节点
    if (i<0){
        return NULL;}
    LSNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i-1){
        //->左边为指针 功能与. 相同
        p=p->next;
        j++;
    }
    return p;
}

bool Push(StockList &L, int e){
    if (i<1)
        return false;
    LSNode *p;
    int j=0;
    p=L;
    int i = L.top;
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
    LSNode *q=p->next;
    e=q->data;
    p->next = q->next;
    free(q);
    return true;
}


int main(){
LinkStock l;
InitStockwithHN(l,l);
pop(l,1);
}