class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto ast : asteroids){
             
                bool alive = true;
                while(!st.empty() && alive && ast < 0 && st.top() > 0){
                    if(st.top() > -ast){
                        alive = false;
                    }
                    else if(st.top() < -ast){
                        st.pop();
                    }else{
                        st.pop();
                        alive = false;
                    }
                }
                if(alive){
                    st.push(ast);
                }
            
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};