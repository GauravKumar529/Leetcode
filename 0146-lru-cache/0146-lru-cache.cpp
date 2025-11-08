class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator , int >> mpp;
    int n ; 
    LRUCache(int capacity) {
        n =capacity;
        
    }
    void BlackBox(int key ){
        dll.erase(mpp[key].first);
        //pushat front ;
        dll.push_front(key);
        // update the adress 
        mpp[key].first =  dll.begin();
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        // erase and update function 
        BlackBox(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
       if(mpp.find(key)  != mpp.end()) 
        {
            // mpp[key].second  =value ;
            mpp[key].second = value ;
            BlackBox(key);

        }
        else {
            dll.push_front(key);
            mpp[key] = {dll.begin() , value };
            n--;
        }
        if(n <0){
            int key_to_be_deleted = dll.back();
            mpp.erase(key_to_be_deleted);
            dll.pop_back();
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */