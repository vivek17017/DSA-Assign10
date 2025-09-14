#define QUEUE_OVERFLOW 1;
#define QUEUE_UNDERFLOW 2;
#include<iostream>
using namespace std;
class Queue{
    private:
        int capacity;
        int front;
        int rear;
        int* ptr;
    public:
        Queue(int);
        void insertion(int);
        bool isFull();
        bool isEmpty();
        int viewRear();
        int viewFront();
        int deletion();
        ~Queue();
        int countElements();
        void reverse(Queue&);

};
Queue::Queue(int cap){
    if(cap<0)
        cap=10;
    ptr=new int[cap];
    capacity=cap;
    front=-1;
    rear=-1;
}
bool Queue::isFull(){
    int r=rear;
    if(rear==capacity-1)
    r=0;
    return ((r+1)==front); 

}
bool Queue::isEmpty(){
    return (rear==-1&&front==-1);

}
void Queue::insertion(int element){
    if(isFull())
        throw QUEUE_OVERFLOW;
    if(front==-1)
    front=0;
    if(rear+1==capacity)
    rear=-1;
    ptr[rear+1]=element;
    rear++;
}
int Queue::viewRear(){
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    return ptr[rear];
}
int Queue::viewFront(){
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    return ptr[front];
}
int Queue::deletion(){
    if(isEmpty())
        throw QUEUE_UNDERFLOW;
    int item;
    item=ptr[front];
    if(rear==front)
    {
        rear=-1;
        front=-1;
    }
    else if(front==capacity-1){
        front=0;
    }
    else{
    front++;
    }
    return item;
}

Queue::~Queue(){
    delete[]ptr;
}
int Queue::countElements(){
    if(isEmpty())
        return 0;
    int count=0;
    int i=front;
    while (i!=rear)
    {
        if(i+1==capacity)
        i=-1;
        count++;
        i++;
    }
    return count+1;

}
int main(){
    Queue r(5);
    r.insertion(1);
    r.insertion(2);
    r.insertion(3);
    r.insertion(4);
    r.insertion(10);
    r.deletion();
    r.deletion();
    r.deletion();
    r.deletion();
    r.insertion(20);
    r.insertion(30);
    cout<<r.viewFront()<<endl;
    cout<<r.viewRear()<<endl;
    
    cout<<"number of elements "<<r.countElements();
}