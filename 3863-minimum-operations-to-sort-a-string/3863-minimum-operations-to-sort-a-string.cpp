class Solution {
public:
    int minOperations(string s) {

        if(s.size() == 1)return 0;

        bool is_sort = true;

        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] < s[i-1]){
                is_sort = false;
                break;
            }
        }

        if(is_sort)return 0;

        // -1  condtion
        if(s.length() == 2 && s.front() > s.back())return -1;

        int lar = 0 , sma = 0;
        int i = 1;

        while(i < s.size()){
            if(s[i] >= s[lar])lar = i;
            
            if(s[i] < s[sma])sma = i;

            i++;
        }

        if(lar == s.size()-1 || sma == 0)return 1;

        if(lar == 0 && sma == s.size()-1)return 3;

        return 2;
    }
};