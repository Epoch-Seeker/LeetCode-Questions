class Solution {
public:
    string smallestPalindrome(string s) {
        map<char , int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        int n = s.size();

        string ans(n , 'a');
        int x=0 , j = n-1;

        for(auto i : mp){
            if(i.second % 2 !=0){
                ans[n/2]=i.first;
                i.second--;
            }
            while(i.second>0){
                ans[x++] = i.first;
                ans[j--] = i.first;
                i.second-=2;
            }
        }

        return ans;
    }
};