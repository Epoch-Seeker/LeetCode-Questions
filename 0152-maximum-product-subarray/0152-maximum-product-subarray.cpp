class Solution {
public:
    int solve(vector<int> nums){
        int neg = 0;
        for(int i: nums){
            if(i < 0)neg++;
        }
        if(neg%2==0){
            int ans = 1;
            for(int i: nums){
                ans*=i;
            }
            return ans;
        }else{
            if(nums.size() == 1)return nums[0];
            int first_neg = 0;
            while(first_neg < nums.size()){
                if(nums[first_neg] < 0)break; 
                first_neg++;
            }

            int last_neg = nums.size()-1;
            while(last_neg >=0){
                if(nums[last_neg] < 0)break; 
                last_neg--;
            }

            int a = 1;
            int b = 1;

            for(int i=0;i< last_neg ; i++){
                a *= nums[i];
            }

            for(int i = first_neg+1 ; i< nums.size(); i++){
                b *= nums[i];
            }

            return max(a , b);

        }
    }
    int maxProduct(vector<int>& nums) {
        bool flag = false;

        vector<int> temp;

        int ans = INT_MIN;

        for(int i : nums){
            if(i == 0){
                flag = true;
                if(!temp.empty()){
                    ans = max(ans , solve(temp));
                    temp.clear();
                }
            }else temp.push_back(i);
        }

        if(!temp.empty()){
            ans = max(ans , solve(temp));
            // temp.clear();
        }

        if(flag)ans = max(ans , 0);

        return ans;
    }
};