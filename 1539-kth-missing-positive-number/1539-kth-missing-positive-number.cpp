class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;
        int mid;
        int ans=0;
        while(s<=e){
            mid=s+(e-s)/2;
            if((arr[mid]-mid-1)<k){
                s=mid+1;
            }
            else if((arr[mid]-mid-1)>k){
                ans=k+mid;
                e=mid-1;
            }
            else{
                ans=k+mid;
                e=mid-1;
            }

        }
        if(ans){
            return ans;
        }
        if(mid==0 && arr[0]>k){
            return k;
        }
        return k+arr.size();
    }
};