class Solution {
public:
    string intToRoman(int num) {
         
        string s = to_string(num);
        int l = s.size();
        l--;
        string ans ;

        for(char ch : s){

            int k = ch - '0';
            int t = k * pow(10 , l);
            l--;

            if(k != 4 && k!= 9){
                if(t >= 1000){
                    while(t > 0){
                        ans += "M";
                        t-=1000;
                    }
                }else if(t >= 100){
                    if(t >= 500){
                        ans += "D";
                        t -= 500;
                    }
                    while(t >0){
                        ans += "C";
                        t -= 100;
                    }
                }else if(t >= 10){
                    if(t >= 50){
                        ans += "L";
                        t -= 50;
                    }
                    while(t >0){
                        ans += "X";
                        t -= 10;
                    }
                }else{
                    if(t >= 5){
                        ans += "V";
                        t -= 5;
                    }
                    while(t >0){
                        ans += "I";
                        t --;
                    }
                }
            }else {
                if(t >= 100){
                    if(t == 400)ans += "CD";
                    else ans += "CM";
                }else if(t >= 10){
                    if(t == 40)ans += "XL";
                    else ans += "XC";
                }else{
                    if(t == 4)ans += "IV";
                    else ans += "IX";
                }
            }
        }

        return ans;
    }
};