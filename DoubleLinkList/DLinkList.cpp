#include <stdio.h>
#include <stdlib.h>
//前插，后插，按位序插
//前插和按位序插都可以通过后插操作来实现！！
typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
    
}DNode,*DLinkList;

//p结点之后插如s结点
bool InsertNextDNode(DNode *p, DNode *s){
if(p==NULL || s==NULL)
    return false;
s->next=p->next;
//p节点后面的节点是不是空
if (p->next != NULL)
    p->next->prior=s;
s->prior = p;
p->next=s;
return true;
}

//删除p结点的后继节点
bool DeleteNextDNode(DNode *p){
if (p==NULL)
    return false;
DNode *q = p->next;
if(q==NULL)
    return false;
p->next=q->next;
if(q->next!= NULL)
    q->next->prior=p;
free(q);
return true;
}

//销毁双链表
void DestoryList(DLinkList &L){
    while(L->next!=NULL)
        DeleteNextDNode(L);
    free(L);
    L=NULL;
}

//带头节点的初始化
bool InitDLinkList(DLinkList &L){
L =(DNode*)malloc(sizeof(DNode));
if (L==NULL)
    return false;
//头节点之前的节点永远是null
L->prior=NULL;
L->next = NULL;
return true;
}

void printDLinkList(DLinkList &L){
for (int i=0;i<10;i++){
DLinkList q=(DNode*)malloc(sizeof(DNode));
q->data=i;
InsertNextDNode(L,q);
L=L->next;
}
}
void printDLinkLista(DLinkList &L){
while (L!=NULL){
    printf("\n%d\n",L->data);
    L=L->prior;
}

}

int main(){
    DLinkList L;
    InitDLinkList(L);
    printDLinkList(L);
    printf("111");
    printDLinkLista(L);
}