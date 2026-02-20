class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> substrings;
        int count = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') count++;
            else count--;
            
           
            if (count == 0) {
                
                string inner = s.substr(start + 1, i - start - 1);
                substrings.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }
        
        
        sort(substrings.begin(), substrings.end(), greater<string>());
        
        
        string result = "";
        for (string &str : substrings)
            result += str;
        
        return result;
    }
};