class Solution {
public:
    #include <numeric>
    int splitArray(vector<int>& nums, int k) {
        int e=accumulate(nums.begin(),nums.end(),0);
        int s=0;
        int mid;
        int ans;
        while(s<=e){
            int sum=0;
            int cnt=0;
            int flag=0;
            mid=s+(e-s)/2;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>mid){
                    flag=1;
                    break;
                }
                if(sum+nums[i]<=mid){
                    sum+=nums[i];
                }
                else{
                    cnt++;
                    sum=nums[i];
                }
            }
            if(flag){
                s=mid+1;
                continue;
            }
            cnt++;
            if(cnt>k){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
        
    }
};