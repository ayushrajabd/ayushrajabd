class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(char c:text){
            if(c=='b')b++;
            else if(c=='a')a++;
            else if(c=='l')l++;
            else if(c=='o')o++;
            else if(c=='n')n++;

        }
        l=l/2;o=o/2;
        int ans=1e9;
        ans=min(ans,b);
        ans=min(ans,a);
        ans=min(ans,l);
        ans=min(ans,o);
        ans=min(ans,n);

        return ans;

    }
};