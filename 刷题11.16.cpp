// 设计循环队列 

// 关键点总结:
// 	容量为所需容量+1, 因为是循环, 所以加减的相关容量的操作都要使用取模操作
class MyCircularQueue {
    int front;
    int rear;
    int capacity;
    vector<int> elements;
public:
    MyCircularQueue(int k) {
        capacity = k + 1;
        rear = 0;
        front = 0;
        elements = vector<int>(capacity);
    }
    
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return elements[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return elements[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return ((rear + 1) % capacity) == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */