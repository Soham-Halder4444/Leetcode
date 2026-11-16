class Solution {
public:
    void threeSum(vector<int>& nums,long long int target,int x, vector<int>&curr,vector<vector<int>>&ans) {
        int n=nums.size();
        for(int i=x; i<n-2; i++) {
            if(i > x && nums[i] == nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];
                if(sum == target) {
                    curr.push_back(nums[i]);
                    curr.push_back(nums[l]);
                    curr.push_back(nums[r]);
                    ans.push_back(curr);
                    curr.pop_back();
                    curr.pop_back();
                    curr.pop_back();
                    while(l < r && nums[l] == nums[l+1]) l++;
                    while(l < r && nums[r] == nums[r-1]) r--;
                    l++; r--;
                } else if(sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>curr;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int x = i+1;
            curr.push_back(nums[i]);
            threeSum(nums,target-nums[i],x,curr,ans);
            curr.pop_back();
        }
        return ans;
    }
};