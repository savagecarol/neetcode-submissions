class Twitter {
    int timestamp = 0;
    unordered_map<int , vector<pair<int , int>>> t;
    unordered_map<int , vector<int>> f;

public:
    Twitter() {
        
    }
    

    void postTweet(int userId, int tweetId) {
        t[userId].push_back({tweetId ,timestamp});
        timestamp++;
    }
    
    vector <int> getNewsFeed(int userId){
         int n = f[userId].size();
    

         vector<pair<int , int>> x;
         vector<int> ans;
         
         for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < t[f[userId][i]].size();j++){
                    x.push_back(t[f[userId][i]][j]);
            }
         }
         for(auto post : t[userId]) x.push_back(post);

        auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;  
        };

        priority_queue<pair<int , int>, vector<pair<int , int>>, decltype(cmp)> pq(cmp);

         for(int i = 0 ; i < x.size();i++){
                pq.push(x[i]);
                if(pq.size() > 10){
                    pq.pop();
                }
         }

         while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
         }
        reverse(ans.begin() , ans.end());
         return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        for (int x : f[followerId]) {
            if (x == followeeId) return; 
        }
    f[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         int n = f[followerId].size();
         int i = 0;
         for(i = 0 ; i < n ; i++){
            if(f[followerId][i] == followeeId) break;   
         }
         if(i < n)
         f[followerId].erase(f[followerId].begin()+i);
    }
};
