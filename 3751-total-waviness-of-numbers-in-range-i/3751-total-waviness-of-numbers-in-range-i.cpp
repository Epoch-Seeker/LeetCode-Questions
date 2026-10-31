class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int i = num1; i <= num2 ; i++){
            string s = to_string(i);

            if(s.size() < 3)continue;

            for(int j = 1 ; j < s.size() - 1; j++){
                int a = s[j-1] - '0';
                int b = s[j] - '0';
                int c = s[j+1] - '0';

                if(b > a && b > c)ans++;
                
                if(b < a && b < c)ans++;
            }
        }

        return ans;
    }
};