class Solution {
public:
    bool bol(int x){
        if(x<0)return true;
        else return false;
    }
    int reverse(int x) {
        long long result=0;
        if(x==0)return 0;
        
        while(x!=0){
            ;
            int temp=x%10;
            if(result>INT_MAX/10||result<INT_MIN/10)return 0;
            result=(result*10)+temp;
        
            x=x/10;
        }
        if(0) {return -1*result;}
        return result;
       
    }
};