class MyCircularQueue {
public:
    int arr[1001],front=0,rear=-1,n,count=0;
    MyCircularQueue(int k) {
        n=k;
    }
    
    bool enQueue(int value) {
        if(((rear+1)%n==front && count>0))
        {
            return false;
        }
        rear=(rear+1)%n;
        arr[rear]=value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(((rear+1)%n==front && count<=0))
        {
            return false;
        }
        front=(front+1)%n;
        count--;
        return true;
    }
    
    int Front() {
        if(((rear+1)%n==front && count==0))
        {
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(((rear+1)%n==front && count==0))
        {
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        return ((rear+1)%n==front && count==0);
    }
    
    bool isFull() {
        return ((rear+1)%n==front && count>0);
    }
};
