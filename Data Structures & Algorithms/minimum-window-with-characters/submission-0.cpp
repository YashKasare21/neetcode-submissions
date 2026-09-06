class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() >  s.length()) return "";

        unordered_map<char, int> countT;
        for(char c : t) countT[c]++;

        unordered_map<char, int> window;
        int have = 0, need = countT.size();
        int left = 0;
        pair<int, int> res = {-1,-1};
        int minLen = INT_MAX;

        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }
            while(have == need){
                if((right - left + 1) < minLen){
                    res = {left, right};
                    minLen = right - left + 1;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if(countT.count(leftChar) && window[leftChar] < countT[leftChar]){
                    have--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(res.first, minLen);
    }
};
