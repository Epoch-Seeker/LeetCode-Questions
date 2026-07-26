class Solution {
public:
    bool check(string& s , int i , int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        // if(s.size()==1)return s;
        string ans ;

        for(int i=0;i<s.size();i++){
            for(int j = i+1 ; j<s.size() ; j++){
                if(s[j] == s[i]){
                    string temp;
                    if(check(s , i , j)){
                        if(j-i+1 > ans.size()){
                            for(int k = i ; k<=j ; k++){
                                temp.push_back(s[k]);
                            }
                            ans = temp;
                        }
                    }
                }
            }
            if(ans.length() == 0)ans = s[i];
        }

        return ans;
    }
};