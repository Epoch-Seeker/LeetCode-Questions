class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , int> d;
        map<int , map<string , vector<string>>> mp;

        for(auto s : strs){
            sort(s.begin() , s.end());
            d[s]++;
        }

        for(auto s : strs){
            string temp = s;
            sort(s.begin() , s.end());
            mp[d[s]][s].push_back(temp);
        }

        vector<vector<string>> ans;

        for(auto t : mp){
            for(auto j : t.second){
                ans.push_back(j.second);
            }
        }
        
        return ans;

    }
};