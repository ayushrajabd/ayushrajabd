class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastlower(26, -1);
        vector<int> firstupper(26, -1);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (islower(c)) {
                lastlower[c - 'a'] = i;
            } 
            else {
                if (firstupper[c - 'A'] == -1) {
                    firstupper[c - 'A'] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (lastlower[i] != -1 &&
                firstupper[i] != -1 &&
                lastlower[i] < firstupper[i]) {
                count++;
            }
        }

        return count;
    }
};