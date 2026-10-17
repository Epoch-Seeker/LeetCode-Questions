class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int , int>> v;
        for(int num : nums){
            int first = 0;
            int second = num;

            while(num){
                first += (num % 10);
                num /= 10;
            }

            v.push_back({first , second});
        }

        sort(v.begin() , v.end());

        unordered_map<int , int> mp;

        for(int i = 0; i< n ; i++){
            auto t = v[i];
            mp[t.second] = i;
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || mp[nums[i]] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = mp[nums[j]];
                cycleSize++;
            }

            ans += cycleSize - 1;
        }

        return ans;

    }
};