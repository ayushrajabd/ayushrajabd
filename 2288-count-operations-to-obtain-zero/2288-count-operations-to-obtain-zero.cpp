class Solution {
public:
    int countOperations(int num1, int num2) {
        long long count =0;
        while(num1!=0&&num2!=0){
            if(num1>=num2){
                count++;
                num1-=num2;
            }
            else{
                count++;
                num2-=num1;
            }

        }return count;
    }
};