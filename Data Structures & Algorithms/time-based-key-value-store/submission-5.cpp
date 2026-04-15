class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>> x;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        x[key].push_back({timestamp , value });
    }
    
    string get(string key, int timestamp) {

        if (x.find(key) == x.end()) return "";
        vector<pair<int, string>>& value = x[key];
        int i = 0 , j = value.size()-1;
        string result = "";
        while(i <= j){
            int mid = i + (j-i)/2;
            if(value[mid].first == timestamp) return value[mid].second;
            else if(value[mid].first < timestamp) {
                result = value[mid].second; 
                i = mid+1;
            }
            else j = mid-1;
        }
        return result;
    }
};
