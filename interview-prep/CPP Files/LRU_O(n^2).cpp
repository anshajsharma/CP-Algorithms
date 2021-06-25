// quesLink : https://leetcode.com/problems/lru-cache/
class LRUCache {
private:
     int m[3001]={0};
     list<int>dq;
     map<int,list<int>::iterator> mp;
     int mxSize;
public:
    LRUCache(int capacity) {
        // constructor for cache
        mxSize = capacity;
        // q.clear();
        dq.clear();
        mp.clear();
    }
    
    int get(int key) {
        if(m[key])
        {
                dq.erase(mp[key]);
                dq.push_front(key);
                mp[key] = dq.begin();
                return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m[key]){
                dq.erase(mp[key]);
            }
       else if(dq.size()>=mxSize)
        {
            int f = dq.back();
            m[f]=0;
            mp.erase(f);
            dq.pop_back();
        }
        dq.push_front(key);
        mp[key] = dq.begin();
        m[key]=value;  
    }
};
