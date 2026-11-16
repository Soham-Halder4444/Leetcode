class Solution {

public:
    int start=-1;;
    int end=-1;
    void startingposition(vector<int>& nums, int target,int s,int e){
        if(s>e || s>=nums.size()){
            return;
        }
        int mid=s+(e-s)/2;
        if(nums[mid]<target){
            startingposition(nums,target,mid+1,e);
        }
        else if(nums[mid]>target){
            startingposition(nums,target,s,mid-1);
        }
        else{
            start=mid;
            startingposition(nums,target,s,mid-1);
        }
        
    }
    void endingposition(vector<int>& nums, int target,int s,int e){
        
        if(s>e  || s>=nums.size()){
            return;
        }
        int mid=s+(e-s)/2;
        if(nums[mid]<target){
            endingposition(nums,target,mid+1,e);
        }
        else if(nums[mid]>target ){
            endingposition(nums,target,s,mid-1);
        }
        else{
            end=mid;
            endingposition(nums,target,mid+1,e);
        }
       
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size();
        startingposition(nums,target,s,e);
        endingposition(nums,target,s,e);
        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};