class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)return {};
         
        unordered_map<string , int> mp;
        vector<string> ans;

        for(int i=0; i <= s.size()-10 ; i++){
            string temp = s.substr(i , 10);
            mp[temp]++;

            if(mp[temp] == 2){
                ans.push_back(temp);
            }
        }

        return ans;

    }
};