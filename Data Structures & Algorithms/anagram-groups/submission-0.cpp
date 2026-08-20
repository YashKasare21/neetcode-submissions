class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for(const string& s: strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); /// isse humein ek common key mil skti hai

            //abh org string ko iss sorted key mei group krdo
            anagramMap[sorted_s].push_back(s);

        }

        vector<vector<string>> result;
        //saare group vectors ko map se extract karo
        for(auto const& pair : anagramMap){
            result.push_back(pair.second);
        }

        return result;
    }
};
