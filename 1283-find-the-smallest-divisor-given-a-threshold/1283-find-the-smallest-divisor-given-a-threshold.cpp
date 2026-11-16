class Solution {
public:
    #include<cmath>
    int smallestDivisor(vector<int>& nums, int threshold) {
        int e=*max_element(nums.begin(),nums.end());
        int s=1;
        int mid;
        int ans;
        int sum;
        while(s<=e){
            mid=s+(e-s)/2;
            sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=ceil((double)nums[i]/mid);
            }
            if(sum>threshold){
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