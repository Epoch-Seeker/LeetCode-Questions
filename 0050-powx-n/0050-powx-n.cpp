class Solution {
public:
    double myPow(double x, int n) {
        
        double res =  exp(n*log(abs(x)));

        if(x < 0){
            if(n%2==0){
                return res;
            }else return -res;
        }

        return res;
    }
};