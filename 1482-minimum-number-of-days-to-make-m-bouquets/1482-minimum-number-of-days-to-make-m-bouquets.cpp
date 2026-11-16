class Solution {
public:
    #include<algorithm>
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)bloomDay.size()<(long long)m*k){
            return -1;
        }
        int e=*max_element(bloomDay.begin(), bloomDay.end());
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int mid;
        int ans;
        while(s<=e){
            mid=s+(e-s)/2;
            int bc=0;
            int fc=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    fc++;
                    if(fc==k){
                        bc++;
                        fc=0;
                    }
                }
                else{
                    fc=0;
                }
            }
            if(bc<m){
                s=mid+1;
            }
            else{
                e=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};