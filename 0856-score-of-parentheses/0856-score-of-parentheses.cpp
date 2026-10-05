class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<pair<char , int>> st;

        int i=0 , n = s.size();

        while(i < n){
            if(s[i] == '(')st.push({s[i] , 0});
            else {
                int temp = 0;

                while(!st.empty() && st.top().first != '('){
                    if(st.top().first == '*')temp+=st.top().second;
                    st.pop(); 
                }

                // pop (,0
                st.pop();

                if(temp == 0)st.push({'*' ,1});

                else st.push({'*' , 2*temp});

            }
            i++;
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top().second;
            st.pop();
        }

        return ans;
    }
};