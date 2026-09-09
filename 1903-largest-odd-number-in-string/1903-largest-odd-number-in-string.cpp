class Solution {
public:
    string largestOddNumber(string num) {
        int back = num.size()-1;

        while(back >=0){
            int t = num[back] - '0';
            if(t % 2 != 0)break;
            back--;
        }

        return num.substr(0 , back+1);
    }
};