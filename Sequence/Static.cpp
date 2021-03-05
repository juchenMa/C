#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
//顺序表的特点空间上连续的。包括静态实现和动态实现
//静态顺序表的特点：无法扩展长度，可能会有脏数据
//定义结构体SeqList
typedef struct{
   int data[MaxSize];
   //初始长度 c语言会自动给int类型设置一个初始值 但是编译器不同初始值也不同
   int length;
}SeqList;
//该初始化可有可无 如果没有可能会存在脏数据    
void InitList(SeqList &L){
    for (int i=0; i<MaxSize;i++)
        L.data[i]=0;
    L.length=0;
}
// i 为插入位置； e为插入数据
bool ListInsert(SeqList &L, int i, int e){
    //判断插入位置是否合法
    if (i<1 || i>L.length+1)
        return false;
    //判断顺序表是否满了
    if (L.length >= MaxSize)
        return false;
    for (int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}
//e为删除的值,引用符号&使此处的e就是main里面的e。如果去掉的话,此处为main中e的数值的一份拷贝.
bool ListDelete(SeqList &L, int i, int &e){
    //判断插入位置是否合法
    if (i<1 || i>L.length+1)
        return false;
    e=L.data[i-1];
    for (int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
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
    int e=-1;
    ListDelete(L, 3,e);
    return 0;
}
