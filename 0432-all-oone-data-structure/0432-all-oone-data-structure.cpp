class AllOne {
public:
    unordered_map<string , int> mp;
    priority_queue<pair<int , string>> maxHeap;
    priority_queue<pair<int  , string> , vector<pair<int , string>> , greater<pair<int , string>>> minHeap;

    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
        maxHeap.push({mp[key] , key});
        minHeap.push({mp[key] , key});
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key] == 0){
            mp.erase(key);
            return;
        }
        maxHeap.push({mp[key] , key});
        minHeap.push({mp[key] , key});
    }
    
    string getMaxKey() {
        while(!maxHeap.empty()){
            auto tp = maxHeap.top();
            if(mp.count(tp.second) && mp[tp.second] == tp.first){
                return tp.second;
            }else maxHeap.pop();
        }
        return "";
    }
    
    string getMinKey() {
        while(!minHeap.empty()){
            auto tp = minHeap.top();
            if(mp.count(tp.second) && mp[tp.second] == tp.first){
                return tp.second;
            }else minHeap.pop();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */