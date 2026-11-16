class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int curr;
        int i=0;
        int j=n;
        while(i<=m && j>=0){
            curr=matrix[i][j];
            if(curr>target){
                j--;
            }
            else if(curr<target){
                i++;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};