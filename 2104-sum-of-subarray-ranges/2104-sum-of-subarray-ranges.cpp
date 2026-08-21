class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n =nums.size();
        vector<int> leftmin(n , 0) , rightmin(n , 0);
        vector<int> leftmax(n , 0) , rightmax(n , 0);
        stack<int> st;

        // previous minimum
        for(int i=0;i< n ;i++){
            while(!st.empty() && nums[st.top()] > nums[i])st.pop();
            leftmin[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

        // next minimum 
        for(int i= n-1 ; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i])st.pop();
            rightmin[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        while(!st.empty())st.pop();

        // previous maximum
        for(int i=0;i< n ;i++){
            while(!st.empty() && nums[st.top()] < nums[i])st.pop();
            leftmax[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

        // next minimum 
        for(int i= n-1 ; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i])st.pop();
            rightmax[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        for(int i=0;i< n;i++){
            long long cont = (long long)(leftmax[i]*rightmax[i]);
            ans += ((long long)nums[i]*cont);
            cont = (long long)(leftmin[i]*rightmin[i]);
            ans -= ((long long)nums[i]*cont);
        }
        return ans;
    }
};