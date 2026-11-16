class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        int mid=start+(end-start)/2;
        if(start>end){
            return -1;
        }
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            if(nums[0]>nums[1]){
                return 0;
            }
            return 1;
        }
        if(0<mid && mid<nums.size()-1){
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else{
                return max(solve(nums,start,mid-1),solve(nums,mid+1,end));
            }
        }
        else{
            if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return mid;
                }
                else{
                    return solve(nums,mid+1,end);
                }
            }
            else{
                if(nums[mid]>nums[mid-1]){
                    return mid;
                }
                else{
                    return solve(nums,mid+1,end);
                }
            }
        }
    }
    int findPeakElement(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};