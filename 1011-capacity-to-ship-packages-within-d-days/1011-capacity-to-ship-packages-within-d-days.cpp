class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int s=1;
        int e=sum;
        int mid;
        int ans;
        while(s<=e){
            sum=0;
            int flag=0;
            int day=0;
            mid=s+(e-s)/2;
            for(int i=0;i<weights.size();i++){ 
                if(weights[i]>mid){
                    flag=1;
                    s=mid+1;
                    break;
                }
                if(sum+weights[i]>mid){
                    sum=0;
                    day++;
                }
                sum+=weights[i];
            }
            if(flag){
                continue;
            }
            day++;
            if(day>days){
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