class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> upper,lower;
        for(char c:word){
            if(isupper(c)){
                upper.insert(c);
            }
            else{
                lower.insert(c);

            }
        }
        int cnt=0;
        for(char c:lower){
            if(upper.count(toupper(c))){
                cnt++;
            }
        }
        return cnt;
    }
};