class ProductOfNumbers {
public:
    vector<int> ans;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0){
            ans.clear();
        }
        else{
            if(ans.empty())ans.push_back(num);
            else ans.push_back(ans.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n = ans.size();
        if(k > n)return 0;
        if(k == n)return ans.back();
        return ans.back()/ans[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */