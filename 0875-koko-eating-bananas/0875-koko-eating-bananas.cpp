class Solution {
public:
    int maximumval(vector<int>& piles){
        int maxi=piles[0];
        for(int i=1;i<piles.size();i++){
            if(piles[i]>maxi){
                maxi=piles[i];
            }
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=maximumval(piles);
        int ans=e;
        int mid=s+(e-s)/2;
        while(s<=e){
            int hour=h;
            for(int i=0;i<piles.size();i++){
                hour-=(piles[i]+mid-1)/mid;// ceil(p/mid)
            }
            if(hour>=0){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};