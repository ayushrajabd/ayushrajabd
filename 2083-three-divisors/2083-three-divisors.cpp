class Solution {
public:
    bool isThree(int n) {
        int count=0;bool ans=true;
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                count++;
            }

        }
        if(count>1||count==0){
            ans=false;
        }

       return ans
       ; 
    }
};