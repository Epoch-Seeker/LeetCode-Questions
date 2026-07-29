class Solution {
public:
    int reverse(int x) {

        bool neg = false;
        if(x < 0)neg = true;
        int p = 0;

        long long temp = abs((long long)x);

        while(temp >= 10){
            p++;
            temp /= 10;
        }

        temp = abs((long long)x);

        long long ans = 0;

        while(temp){
            int t = temp % 10;

            ans += (t * pow(10 , p--));

            if(neg){
                if(-1*ans < INT_MIN)return 0;
            }else {
                if(ans > INT_MAX)return 0;
            }

            temp /= 10;

        }

        if(neg){
           return -1*ans;
        }else {
            return ans;
        }
    }
};