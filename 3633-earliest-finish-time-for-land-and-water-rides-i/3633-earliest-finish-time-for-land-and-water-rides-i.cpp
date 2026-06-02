class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int landfinish=landStartTime[i]+landDuration[i];
                int finish1=max(landfinish,waterStartTime[j])+waterDuration[j];

                int waterfinish=waterStartTime[j]+waterDuration[j];
                int finish2=max(waterfinish,landStartTime[i])+landDuration[i];
                int temp=min(finish1,finish2);

                ans=min(ans,temp);
            }
        }
        return ans;
    }
};