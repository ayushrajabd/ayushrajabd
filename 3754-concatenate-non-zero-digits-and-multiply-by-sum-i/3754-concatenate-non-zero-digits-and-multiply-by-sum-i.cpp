class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long count=0;
        string s=to_string(n);
        int a=s.size();
        for(int i=0;i<a;i++){
            if(s[i]!='0'){
                ans=ans*10+(s[i]-'0');
                count+=(s[i]-'0');
            }
        }
        long long result=ans*count;
        return result;

    }
};