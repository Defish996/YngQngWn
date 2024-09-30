// 1845. 座位预约管理系统 priority_queue使用

class SeatManager {
private:
    // vector<bool> _switch;
    priority_queue<int, vector<int>, greater<int>> _flag;// 创建小顶堆
    // priority_queue<int> _flag;// 创建大顶堆

public:
    SeatManager(int n) /*: _switch(n, true)*/{
        for(int i = 1; i <= n; i++)
        {
            _flag.push(i);
        }
    }
    
    int reserve() {
        if(_flag.empty()) return 0;
        int seat = _flag.top();   
        _flag.pop(); 
        // _switch[seat - 1] = false;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        // _switch[seatNumber - 1] = true;
        _flag.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
 
 // 此时发现, 虽然逻辑没什么错,但是安排座位的这个_switch纯属是鸡肋, 直接删除 