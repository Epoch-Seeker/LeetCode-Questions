class Solution {
public:
    bool canAliceWin(int n) {
        int k = 10;
        while(n-k >= 0){
            n-=k;
            k--;
        }
        if(k%2 == 0)return false;
        return true;
    }
};