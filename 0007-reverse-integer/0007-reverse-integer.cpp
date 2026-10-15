class Solution {
public:
    int reverse(int x) {

        string temp = to_string(x);
        // temp = temp.substr(1);
        bool neg = (x < 0);

        if (neg) {
            temp = temp.substr(1);
        }

        std::reverse(temp.begin() , temp.end());

        long long p = stoll(temp);
        if(neg)p = -p;

        if( p < INT_MIN || p > INT_MAX){
            return 0;
        }

        return p;

    }
};