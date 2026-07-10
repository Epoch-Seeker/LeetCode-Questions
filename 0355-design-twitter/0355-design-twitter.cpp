class Twitter {
public:
    // kin kin ko follow karta he
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int , vector<pair<int ,int >>> tweets;
    int timer;
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++ , tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        
        priority_queue<vector<int>> pq;

        // push users last tweet {timer , tweet id, user id , idx}
        if(!tweets[userId].empty()){
            int idx = tweets[userId].size()-1;
            pq.push({tweets[userId][idx].first , tweets[userId][idx].second ,userId , idx });
        }

        // push last tweet of the users he follows
        for(auto con : follows[userId]){
            if(!tweets[con].empty()){
                int idx = tweets[con].size()-1;
                pq.push({tweets[con][idx].first , tweets[con][idx].second ,con , idx });
            }
        }

        while(!pq.empty() && ans.size() < 10){
            auto it = pq.top();
            pq.pop();
            int tweetid = it[1];
            int userid = it[2];
            int idx = it[3];
            ans.push_back(tweetid);
            if(idx > 0){
                pq.push({tweets[userid][idx-1].first , tweets[userid][idx-1].second ,userid , idx-1});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);      
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */