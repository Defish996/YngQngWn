class MyHashSet {
private:
    vector<list<int>> vec;
    static const int base=769;
    static int hash(int n)
    {
        return n%base;
    }
public:
    MyHashSet():vec(base) {}
    
    void add(int key) {
        int h = hash(key);
        for (auto it = vec[h].begin(); it != vec[h].end(); it++) {
            if ((*it) == key) {
                return;
            }
        }
        vec[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = vec[h].begin(); it != vec[h].end(); it++) {
            if ((*it) == key) {
                vec[h].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (auto it = vec[h].begin(); it != vec[h].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */