class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mp;
        unordered_map<char , bool> mapped;
        for(int i=0;i<s.size() ; i++){
            if(mp.count(s[i])){
                if(mp[s[i]] != t[i])return false;
                continue;
            }
            if(mapped.count(t[i]))return false;
            mp[s[i]] = t[i];
            mapped[t[i]] = true;
        }

        return true;
    }
};