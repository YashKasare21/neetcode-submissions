class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int left = 0;
        int max_len = 0;

        for(int right = 0; right < s.length(); right++){
            char current_char = s[right];
            if(charIndexMap.find(current_char) != charIndexMap.end() && charIndexMap[current_char] >= left){
                left = charIndexMap[current_char] + 1;
            }

            charIndexMap[current_char] = right;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
