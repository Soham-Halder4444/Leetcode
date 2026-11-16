class Solution {
public:
    int solve(vector<vector<int>> ans,int i,int j){
        if(ans[i][j]!=0){
            return ans[i][j];
        }
        return (solve(ans,i-1,j-1)+solve(ans,i-1,j));
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);  
        for(int i=0; i<rowIndex+1; i++){
            ans[i].resize(i+1);            
            ans[i][0] = 1;                 
            ans[i][i] = 1;                 
        }
        for(int i=2;i<rowIndex+1;i++){
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans[rowIndex];
    }
};