class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        int i=0 , n = s.size();

        while(i < n){
            if(s[i] == '(')st.push(0);
            else {
                int temp = 0;

                while(!st.empty() && st.top() != 0){
                    temp+=st.top();
                    st.pop(); 
                }
                st.pop();

                if(temp == 0)st.push(1);

                else st.push(2*temp);

            }
            i++;
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};