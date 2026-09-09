class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        s += s;

        for(int i=0;i<s.size();i++){
            if(s[i] == goal[0]){
                int p = i+1;
                int q = 1;
                while(q < goal.size()){
                    if(s[p] == goal[q]){
                        p++;
                        q++;
                    }else break;
                }
                if(q == goal.size())return true;
            }
        }

        return false;
    }
};