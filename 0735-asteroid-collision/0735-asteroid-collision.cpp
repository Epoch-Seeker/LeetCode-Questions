class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(auto ast : asteroids){
             
                bool alive = true;
                while(!ans.empty() && alive && ast < 0 && ans.back() > 0){
                    if(ans.back() > -ast){
                        alive = false;
                    }
                    else if(ans.back() < -ast){
                        ans.pop_back();
                    }else{
                        ans.pop_back();
                        alive = false;
                    }
                }
                if(alive){
                    ans.push_back(ast);
                }
            
        }

        
        return ans;
    }
};