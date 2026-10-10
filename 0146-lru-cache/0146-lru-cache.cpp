class LRUCache {
public:
    int capacity;
    vector<pair<int,int>>arr;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        
        int idx = -1;

        for(int i = 0; i < arr.size(); i++){

            if(arr[i].first == key){
                idx = i;
                break;
            }
        }

        if(idx == -1) return -1;
        int val = arr[idx].second;
        arr.erase(arr.begin() + idx);
        arr.push_back({key , val});
        return val;
    }
    
    void put(int key, int value) {
        
        for(int i = 0; i < arr.size(); i++){

            if(arr[i].first == key){

                arr.erase(arr.begin() + i);
                break;
            }
        }

        if(arr.size() == capacity){
            arr.erase(arr.begin());
        }
        arr.push_back({key , value});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */