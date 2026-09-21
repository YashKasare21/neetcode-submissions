class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }
        
        auto& vec = store[key];
        
        // Binary search for largest timestamp <= given timestamp
        int left = 0;
        int right = vec.size() - 1;
        string result = "";
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (vec[mid].first <= timestamp) {
                result = vec[mid].second; // Potential answer
                left = mid + 1; // Try to find a larger timestamp
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};