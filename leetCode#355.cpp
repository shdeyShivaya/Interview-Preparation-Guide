class Twitter {
private:
    unordered_map<int, unordered_map<int, int>> followMap;
    // map[0][0] = 1; map[0][5] = 1; map[0][3] = 0;
    vector<int> feedMap;
    unordered_map<int,vector<int>> feeds;
    int id = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        followMap[userId][userId] = 1;

        id++;
        feedMap.push_back(tweetId);
        feeds[userId].push_back(id);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<int, vector<int>> newsFeed;
        int numFeeds = 0;

        for(auto t:followMap[userId]){
            if(t.second == 1){
                for(int feedId:feeds[t.first]){
                    if(numFeeds == 10){
                        newsFeed.push(-feedId);
                        newsFeed.pop();
                    }
                    else{
                        newsFeed.push(-feedId);
                        numFeeds++;
                    }
                }
            }
        }

        vector<int> nums(numFeeds, 0);
        while(!newsFeed.empty()){
            nums[--numFeeds] = (feedMap[-newsFeed.top() - 1]);
            newsFeed.pop();
        }

        return nums;

    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId][followerId] = 1;
        followMap[followeeId][followeeId] = 1;
        followMap[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId][followeeId] = 0;
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

