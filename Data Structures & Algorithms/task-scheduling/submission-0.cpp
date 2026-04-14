

class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        
        unordered_map<char,int> m;

        auto cmp = [](pair<char , int> &a, pair<char , int> &b){
            return a.second < b.second;
        };

        priority_queue<pair<char , int> , vector<pair<char , int>> , decltype(cmp)> pq(cmp);
        int n = tasks.size();
        for(int i = 0 ; i < n ; i++){
            m[tasks[i]]++;
        }

        for(auto [key , value] : m){
            pq.push({key , value});
        }

        int ans = 0;
        while(!pq.empty()){
            vector<pair<char , int>> v;
            int count = k+1;

            while(count > 0 && !pq.empty()){
                pair<char , int> curr = pq.top(); pq.pop();
                curr.second--;
                v.push_back(curr);
                count--;
                ans++;
            }

            for(auto it: v){
                    if(it.second > 0) pq.push(it);
            }

            if(!pq.empty()) ans+=count;
        }

        return ans;
    }
};
