class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int count5=0;bool ans=true;
       int count10=0;
       int count20=0;
       for(int i=0;i<bills.size();i++){
        if(bills[i]==5)count5++;
        if(bills[i]==10){
            count10++;count5--;
            if(count5<0){ans=false;break;}
            
        };
        if(bills[i]==20){
            count20++;
        if(count5>0&&count10>0){
            count5--;count10--;
        }
        else if(count5>2){
            count5=count5-3;
        }
        else{
            ans=false;break;
        }
        
        
        }

        

       } 
       
       return ans;
    }
};