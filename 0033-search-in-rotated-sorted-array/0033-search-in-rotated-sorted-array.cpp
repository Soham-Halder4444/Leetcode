class Solution {
public:
    int pivot(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            
        }
        return s;
    }
    int binarysearch(vector<int>& nums,int start,int end,int key){
        int s=start;
        int e=end;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]>key){
                e=mid-1;
            }
            else if(nums[mid]<key){
                s=mid+1;
            }
            else{
                return mid;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pi=pivot(nums);
        if(target>=nums[pi] && target<=nums[n-1]){
            return binarysearch(nums,pi,n-1,target);
        }
        else{
            return binarysearch(nums,0,pi-1,target);
        }
    }
};