class Solution {
public:
    double triangleArea(const vector<int> &A,const vector<int> &B,const vector<int> &C){
        return 0.5*abs(
            A[0]*(B[1]-C[1])+
            B[0]*(C[1]-A[1])+
            C[0]*(A[1]-B[1])
        );
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int s=points.size();
        double maxarea=0;
        for(int i=0;i<s;i++){
            for(int j=i+1;j<s;j++){
                for(int k=j+1;k<s;k++){
                    maxarea=max(maxarea,triangleArea(points[i],points[j],points[k]));

                          
                }
            }
        }return maxarea;

    }
};