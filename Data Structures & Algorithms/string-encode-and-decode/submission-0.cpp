class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& s : strs){
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;

    }

    vector<string> decode(string s) {
        vector<string> decoded ;
        int i = 0;

        while(i < s.length()){
            // delimiter "#" ki position find karo
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            // extract the lenght of the upcoming string 
            int lenght = stoi(s.substr(i,j-i));

            // move 'i' past the '#'
            i = j + 1;

            // extract the actual string of the 'lenght' characters
            decoded.push_back(s.substr(i, lenght));

            // move 'i' past the extracted string 
            i += lenght;
        }
        return decoded;
    }
};
