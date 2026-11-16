class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maximum=0;
        int mini;
        mini=prices[0];
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i]);
            if(mini!=prices[i]){
                maximum=max(maximum,prices[i]-mini);
            } 
        }
        return maximum;
    }
};