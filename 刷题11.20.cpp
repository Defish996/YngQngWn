// 使用队列实现栈
// 核心点在于在入栈时, 要将入队前的队列的所有元素个数存下来, 然后进行入队, 将入队前的个数的元素重新入队, 然后完成push
// 其他的都是正常按照stack进行操作就行了

class MyStack {
    queue<int> q;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0; i < n; ++i)
        {
            q.push(q.front());
            q.pop();
        }    
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */