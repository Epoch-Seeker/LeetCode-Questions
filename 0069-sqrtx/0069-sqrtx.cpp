class Solution {
public:
    int mySqrt(int x) {
        long long l = 1;
        long long h = x;

        while(l<=h){
            long long m = l + (h-l)/2.0;
            // cout<<m<<" ";
            long long temp = m*m;
            if(temp == x)return m;
            if(temp < x)l = m+1;
            else h = m-1;
        }

        return l-1;
    }
};