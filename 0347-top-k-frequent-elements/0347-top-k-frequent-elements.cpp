class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> freq;
        for(int i =0 ;i<nums.size() ; i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int , int>> pq;

        for(auto i: freq){
            pq.push({i.second , i.first});
        }

        vector<int> ans;
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};