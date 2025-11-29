class Solution {
public:
    int isreverse(int x){
        int result=0;int c=x;
        while(x!=0){
            int temp=x%10;
            if(result<INT_MIN/10||result>INT_MAX/10)return 0;
            result=result*10+temp;x=x/10;
        }return result;
    }
    bool isPalindrome(int x) {
        int c=isreverse(x);
        if(x<0){return false;}
        if(c==x)return true;
        else return false;
        
    }
};