class Solution {
public:
    int minOperations(string s) {

        int n = s.size();

        if(n == 1)return 0;

        bool is_sort = true;

        for(int i = 1 ; i < n ; i++){
            if(s[i] < s[i-1]){
                is_sort = false;
                break;
            }
        }

        if(is_sort)return 0;

        // -1  condtion
        if(n == 2 && s.front() > s.back())return -1;

        int lar = 0 , sma = 0;
        int i = 1;

        while(i < n){
            if(s[i] >= s[lar])lar = i;
            
            if(s[i] < s[sma])sma = i;

            i++;
        }

        if(lar == n-1 || sma == 0)return 1;

        if(lar == 0 && sma == n-1)return 3;

        return 2;
    }
};