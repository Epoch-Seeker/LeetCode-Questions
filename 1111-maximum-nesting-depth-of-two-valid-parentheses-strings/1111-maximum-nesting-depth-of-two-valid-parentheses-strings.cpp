class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        bool a = true;

        vector<int> ans(seq.size() , 0);

        for(int i = 0; i< seq.size() ; i++){
            char ch = seq[i];
            if(ch == '('){
                if(a){
                    a = false;
                    continue;
                }else {
                    ans[i] = 1;
                    a = true;
                }
            }else{
                if(!a){
                    a = true;
                    continue;
                }else{
                    ans[i] = 1;
                    a = false;
                }
            }
        }

        return ans;
    }
};