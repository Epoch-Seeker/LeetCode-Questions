class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)return {};
        string temp;

        int i=0;
        unordered_map<string , int> mp;

        while(i < s.size()){
            temp += s[i++];
            if(temp.size() == 10)break;
        }

        mp[temp]++;

        while(i < s.size()){
            temp = temp.substr(1);
            temp += s[i++];
            mp[temp]++;
        }

        vector<string> ans;

        for(auto it : mp){
            if(it.second > 1)ans.push_back(it.first);
        }

        return ans;

    }
};