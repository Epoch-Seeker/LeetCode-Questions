class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string>> d;
        map<int , vector<vector<string>>> mp;

        for(auto s : strs){
            string temp = s;
            sort(s.begin() , s.end());
            d[s].push_back(temp);
        }

        for(auto t : d){
            int k = t.second.size();
            mp[k].push_back(t.second);
        }

        vector<vector<string>> ans;

        for(auto t : mp){
            for(auto j : t.second){
                ans.push_back(j);
            }
        }
        
        return ans;

    }
};