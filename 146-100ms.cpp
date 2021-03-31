class LRUCache {
    list<pair<int, int>> lru;
    map<int, list<pair<int, int>>::iterator> mp;
    int cp;
public:
    LRUCache(int capacity) {
        cp = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            lru.push_front(*mp.at(key));
            lru.erase(mp.at(key));
            mp[key] = lru.begin();
            return lru.front().second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            lru.push_front({key, value});
            mp[key] = lru.begin();
            if (mp.size() > cp) {
                mp.erase(lru.back().first);
                lru.pop_back();
            }
        }
        else {
            mp.at(key)->second = value;
            lru.push_front(*mp.at(key));
            lru.erase(mp.at(key));
            mp[key] = lru.begin();
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */