class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        vector<int> count(26,0);

        // for counting freq for s 
        for(char c : s){
            count[c - 'a']++;
        }

        // for decrement freq for t
        for(char c : t){
            count[c - 'a']--;
        }

        // if they are anagrams , all the counts should be 0
        for(int i=0; i<26; i++){
            if(count[i] != 0){
                return false;
            }
        }

        return true;
    }
};
