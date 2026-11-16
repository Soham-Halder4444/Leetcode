class Solution {
public:
    int solve(int index,vector<int>& prices,int m[][2]){
        for(int i=index;i>=0;i--){
            m[i][0]=max(-prices[i]+m[i+1][1],0+m[i+1][0]);
            m[i][1]=max(prices[i]+m[i+1][0],0+m[i+1][1]);
        }
        return m[0][0];
    }
    int maxProfit(vector<int>& prices) {
        int m[prices.size()][2];
        m[prices.size()-1][0]=0;
        m[prices.size()-1][1]=prices[prices.size()-1];
        return solve(prices.size()-2,prices,m);
    }
};