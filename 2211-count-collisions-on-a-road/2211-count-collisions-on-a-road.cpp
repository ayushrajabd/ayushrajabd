class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        if(n==0)return 0;
        int start=0;
        while(start<n&&directions[start]=='L'){
            start++;

        }
        int end=n-1;
        while(end>=0&&directions[end]=='R'){
            end--;
        }
        int ans=0;
        for(int i=start;i<=end;i++){
            if(directions[i]=='L'||directions[i]=='R'){
                ans++;

            }
        }return ans;
    }
};