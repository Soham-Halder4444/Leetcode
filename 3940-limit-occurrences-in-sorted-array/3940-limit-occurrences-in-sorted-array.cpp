class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        int cnt=1;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                if(cnt<k){
                    ans.push_back(nums[i]);
                    cnt++;
                }
            }
            else{
                cnt=1;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};