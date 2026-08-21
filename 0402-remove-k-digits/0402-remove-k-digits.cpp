class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(int i=0;i< n ; i++){
            while(!st.empty() && k >0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        int i =0 ;

        while(i < ans.size()-1 && ans[i]=='0')i++;

        ans = ans.substr(i);

        if(ans.empty())return "0";

        return ans ;
    }
};