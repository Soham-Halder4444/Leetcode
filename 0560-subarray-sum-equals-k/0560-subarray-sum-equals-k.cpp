class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        for(int i=1;i<=nums.size()-1;i++){
            nums[i]+=nums[i-1];
        }
        if(nums.size()==1){
            if(nums[0]==k){
                return 1;
            }
            return 0;
        }
        else{
            for(int i=0;i<=nums.size()-1;i++){
                if(nums[i]==k){
                    ans++;
                }
                if(i+1==nums.size()){
                    break;
                }
                for(int j=i+1;j<=nums.size()-1;j++){
                    if(nums[j]-nums[i]==k){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};