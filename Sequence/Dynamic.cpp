#include <stdio.h>
#include <stdlib.h>
#define InitiSize 10
//定义结构体SeqList
typedef struct{
   int *data;
   int Maxsize;
   int length;
}SeqList;


//初始化
void InitList(SeqList &L){
   L.data=(int *)malloc(InitiSize*sizeof(int));//分配指针
   L.length=0;//当前长度
   L.Maxsize= InitiSize;//最大长度
}

void IncreaseSize(SeqList &L, int len){//len为增加的长度
   int *p=L.data;
   L.data=(int *)malloc((L.Maxsize+len)*sizeof(int));
   for(int i=0;i<L.length;i++){
      L.data[i]=p[i];
   }
   L.Maxsize=L.Maxsize+len;
   free(p);
}
int GetElem(SeqList L,int i){
    return L.data[i-1];
}
int LocateElem(SeqList L,int e){
   for (int i=0; i<L.length;i++)
      if(L.data[i]==e)
         return i+1;
   return 0;
}

int main(){
   SeqList L;
   InitList(L);
   IncreaseSize(L,5);
   L.data[0]=0;

   printf("%d", L.data[0]);
   printf("wwwwwwwwwwhat!!!!!!!");
   return 0;
}