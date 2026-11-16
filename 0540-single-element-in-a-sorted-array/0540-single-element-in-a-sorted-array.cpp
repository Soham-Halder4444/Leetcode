class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        int s=start;
        int e=end;
        int mid=s+(e-s)/2;
        if(s<0 || e>nums.size()-1 || s>e){
            return -1;
        }
        if(mid-1>=0 && nums[mid]==nums[mid-1]){
            return max(solve(nums,s,mid-2),solve(nums,mid+1,e));
        }
        else if(mid+1<=nums.size()-1 && nums[mid]==nums[mid+1]){
            return max(solve(nums,s,mid-1),solve(nums,mid+2,e));
        }
        else{
            return mid;
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        return nums[solve(nums,0,nums.size()-1)];
    }
};