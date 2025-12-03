class Solution {
public:
    void markrow(vector<vector<int>>&matrix,int i){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]!=0){
                matrix[i][j]=INT_MIN;
            }
        }

    }
    void markcol(vector<vector<int>>&matrix,int j){
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][j]!=0){
                matrix[i][j]=INT_MIN;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<bool> row(m,false);
        vector<bool> col(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    col[i]=true;
                    row[j]=true;

                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(col[i]||row[j]){
                    matrix[i][j]=0;
                }
            }
        }
       
        
    }
};