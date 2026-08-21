class Solution {
public:
    int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        
        int ans = 0;
        int n =arr.size();
        vector<int> left(n , 0) , right(n , 0);
        stack<int> st;

        // previous minimum
        for(int i=0;i< n ;i++){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();
            left[i] = st.empty() ? i+1 : i - st.top();
            st.push(i);
        }

        while(!st.empty())st.pop();

        // next minimum 
        for(int i= n-1 ; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])st.pop();
            right[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }

        for(int i=0;i< n ; i++){
            ans += (arr[i]*(long long)(left[i]*right[i])%MOD)%MOD;
            ans %= MOD;
        }

        return ans;
    }
};