class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int s = n - k + 1;
        priority_queue<int> pq;

        for(int i : nums){
            if(pq.size() == s){
                if(i < pq.top()){
                    pq.pop();
                    pq.push(i);
                }
            }
            else pq.push(i);
        }
        return pq.top();
    }
};