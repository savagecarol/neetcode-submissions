class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int key) {
     unordered_map<int, int> freq;
    
    // Step 1: Count frequency
    for(int num : nums){
        freq[num]++;
    }

    // Step 2: Move to vector of pairs
    vector<pair<int,int>> v;
    for(auto &p : freq){
        v.push_back({p.first, p.second});
    }

    // Step 3: Sort by frequency (descending)
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });

    // Step 4: Take first k elements
    vector<int> ans;
    for(int i = 0; i < key; i++){
        ans.push_back(v[i].first);
    }

    return ans;
        
    }
};
