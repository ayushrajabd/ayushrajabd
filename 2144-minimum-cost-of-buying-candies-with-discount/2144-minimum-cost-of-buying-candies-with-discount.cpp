class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        int ans=0;
        sort(cost.begin(),cost.end());
        while(n>=2){
            int c1=cost[n-1];
            int c2=cost[n-2];
            ans+=(c1+c2);
            n=n-3;
        }


        
        if(n==1){
            ans+=cost[0];
        }
        
        return ans;
    }
};