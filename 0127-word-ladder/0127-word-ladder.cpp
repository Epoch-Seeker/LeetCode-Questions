class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(!st.count(endWord))
            return 0;

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
                    if(ch == temp)continue;
                    s[i] = ch;
                    if(st.count(s)){
                        st.erase(s);
                        q.push({s , no + 1});
                    }
                }
                s[i] = temp;
            }
        }

        return 0;
    }
};