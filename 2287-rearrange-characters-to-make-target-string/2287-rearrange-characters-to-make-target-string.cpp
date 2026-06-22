class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cntS(26,0),cntT(26,0);
        for(char c:s){
            cntS[c-'a']++;
        }
        for(char c:target){
            cntT[c-'a']++;
        }
        int ans=1e9;
        for(int i=0;i<26;i++){
            if(cntT[i]>0){
                ans=min(ans,cntS[i]/cntT[i]);
            }
        }
        return ans;


    }
};