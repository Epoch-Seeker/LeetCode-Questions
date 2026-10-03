class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char , int>> st;

        for(char ch : s){
            if(ch == '('){
                st.push({ch , 0});
            }
            else {
                int temp = 0;

                while(!st.empty() && st.top().first == '*'){
                    temp += st.top().second;
                    st.pop();
                }

                // check for (
                if(!st.empty() && st.top().first == '('){
                    st.pop();
                    st.push({'*' , temp + 1});
                }

                else {
                    if(temp > 0)st.push({'*' , temp});
                    st.push({')' , 0});
                }
            }
        }


        int ans = 0;

        while(!st.empty()){
            // cout<<st.top().first<<":"<<st.top().second<<" ";
            auto t = st.top();
            st.pop();
            if(t.first != '*')continue;
            if(!st.empty() && st.top().first == '*'){
                st.top().second += t.second;
                continue;
            }
            ans = max(ans , t.second);
        }

        return 2*ans;
    }
};