// 用栈实现队列 
// 核心在于两个栈实现队列时的删除操作, 删除时当outStack为空时再进行in的转移
// 否则就将out输完

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        int x = this->peek();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
        return s2.top(); 
    }
    bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */