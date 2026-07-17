class StockPrice {
public:
    unordered_map<int , int> mp;
    multiset<int> st;
    pair<int , int> cur;
    StockPrice() {
        cur = {0 , -1};
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)){
            st.erase(st.find(mp[timestamp]));
        } 
        st.insert(price);
        mp[timestamp] = price;
        if(timestamp >= cur.first){
            cur = {timestamp , price};
        }
      
    }
    
    int current() {
        return cur.second;
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */