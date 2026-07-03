class Solution {
public:
    int mySqrt(int x) {

        long long res = exp((log(x)*0.5));

        if((res+1)*(res+1) <= x)res++;

        return res;
    }
};