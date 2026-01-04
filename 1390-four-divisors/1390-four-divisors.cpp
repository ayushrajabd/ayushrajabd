class Solution {
public:
    int countofdiv(int a){
        int count=0;int sum=0;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                int d1 = i;
                int d2 = a / i;

                if (d1 == d2) {
                    count++;
                    sum += d1;
                } else {
                    count += 2;
                    sum += d1 + d2;
                }

                if (count > 4) return -1;
            }
        }
        if(count==4)return sum;
        return -1;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n=nums.size();
        int com=0;
        for(int i=0;i<n;i++){
            int ans=countofdiv(nums[i]);
            if(ans!=-1){
                com+=ans;
            }

        }
        return com;
    }
};