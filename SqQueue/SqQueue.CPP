#define MaxSize 10
typedef struct {
    int data[MaxSize];//int == ElemType
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.front=Q.rear=0;
}

void testQueue(){
    SqQueue Q;
    InitQueue(Q); 
}