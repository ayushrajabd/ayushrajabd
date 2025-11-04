class Solution {
public:
    int minSteps(string s, string t) {
       unordered_map<char,int> ump1;
       unordered_map<char,int> ump2;
       for(char c:s){ump1[c]++;}
       for(char c:t){ump2[c]++;}int step=0;
       for(char c='a';c<='z';c++){
        if(ump2[c]>ump1[c]){
            step+=ump2[c]-ump1[c];
        }
       }
       return step;
    }
};