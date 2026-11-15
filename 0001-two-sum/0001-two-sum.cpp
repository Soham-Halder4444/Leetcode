class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int val1=nums[i];
            int x=target-val1;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(nums[j]==x){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans; 
                }
                else{
                    continue;
                }

            }
            
        }
        return ans;    
    }
};