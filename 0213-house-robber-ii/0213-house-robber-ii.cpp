class Solution {
public:
    int solve(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int prev2=nums[0];
        int prev1=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int ans=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>nums1;
        vector<int>nums2;
        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1){
                nums1.push_back(nums[i]);
            }
            if(i!=0){
                nums2.push_back(nums[i]);
            }
        }
        return max(solve(nums1),solve(nums2));
    }
};