class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string , bool> mp;
        for(auto s :wordList ){
            mp[s] = false;
        }

        mp[beginWord] = true;
        queue<pair<string , int>> q;
        q.push({beginWord , 1});

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            string s = t.first;
            int no = t.second;

            if(s == endWord)return no;

            for(int i=0;i< s.size() ; i++){
                char temp = s[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                     
                    s[i] = ch;
                    if(mp.count(s) && !mp[s]){
                        mp[s] = true;
                        q.push({s , no + 1});
                    }
                }
                s[i] = temp;
            }
        }

        return 0;
    }
};