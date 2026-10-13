class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;

        int temp = x;
        long long y = 0;

        while(temp){
            y = y*10 + (long long)(temp%10);
            temp /= 10;
        }

        if(x == y)return true;
        return false;
    }
};