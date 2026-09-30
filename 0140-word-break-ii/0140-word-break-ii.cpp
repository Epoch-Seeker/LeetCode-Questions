class Solution {
public:
    void solve(string s ,vector<string>& wordDict , int start , 
    vector<string>& ans , string& str){
        
        if(start == s.size()){
            ans.push_back(str);
            str.clear();
            return;
        }


        for(int end = start ; end < s.size() ; end++){
            string temp = s.substr(start , end - start +1);
            cout<<temp<<endl;
            auto itr = find(wordDict.begin() , wordDict.end() ,  temp);
            if(itr != wordDict.end()){
                string p = str;
                if(!str.empty())temp = " " + temp;
                str+= temp;
                solve(s , wordDict , end+1 , ans , str);
                str = p;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // vector<int> dp(n , -1);
        vector<string> ans;
        string st = "";
        solve(s , wordDict , 0 , ans , st);
        return ans;
    }
};