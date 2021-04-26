#define MaxSize 10
typedef struct {
    int data[MaxSize];//int == ElemType
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top=-1;
}
//传入的是S本体 不是复制品
bool Push(SqStack &S, int x){
    if(S.top == MaxSize -1 )//判断栈满操作  
        return false;
    S.top = S.top + 1;
    S.data[S.top]=x;
    return true;
}
// 删除栈内的x元素，并返回
//数据元素还是存留在内存中的，只是改变了top的值
bool Pop(SqStack &S, int &x){
    if (S.top == 1 )
        return false;
    x=S.data[S.top];
    S.top = S.top -1;
    return true;
}
bool GetTop(SqStack &S, int &x){
    if(S.top ==  -1 )//判断栈满操作
        return false;
    x = S.data[S.top];
    return true;
}
void testStack(){
    SqStack S;
    InitStack(S);
}