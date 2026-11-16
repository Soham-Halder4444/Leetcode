class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int max=matrix.size()*matrix[0].size();
        int s=0;
        int e=max-1;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]>target){
                e=mid-1;
            }
            else if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]<target){
                s=mid+1;
            }
            else{
                return 1;
            }
        }
        return 0;
        
    }
};