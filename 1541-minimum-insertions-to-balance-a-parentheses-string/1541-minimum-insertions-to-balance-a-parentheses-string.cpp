class Solution {
public:
    int minInsertions(string s) {
        
        string temp;

        for(int i=0; i< s.size() ; i++){
            if(s[i] == ')'){
                if(!temp.empty() && temp.back() == s[i]){
                    temp.pop_back();
                    temp += '*';
                }
                else temp += s[i];
            }else temp += s[i];

            // cout<<temp<<endl;
        }
        
        // cout<<temp;

        int ans = 0;

        for(int i =0; i< temp.size() ; i++){
            if(temp[i] == ')'){
                ans++;
                temp[i] = '*';
            }
        }

        int sum = 0;

        for(char ch : temp){
            if(ch == '(')sum++;
            else sum--;

            if(sum < 0){
                ans++;
                sum = 0;
            }
        }

        while(sum--)ans+=2;
        
        return ans;
    }
};