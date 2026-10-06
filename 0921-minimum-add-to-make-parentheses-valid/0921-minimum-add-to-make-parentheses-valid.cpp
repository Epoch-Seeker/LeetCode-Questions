class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;

        for(char ch : s){
            if(ch == '(')st.push(ch);
            else{

                while(!st.empty() && st.top() != '('){
                    st.pop();
                }

                if(st.empty())ans++;
                else st.pop();
            }
        }

        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
    }
};