class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>fruit;
        int *basketindex=new int[n];
        for(int i=0;i<=n-1;i++){
            basketindex[i]=0;
        }
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=n-1;j++){
                if((fruits.at(i)<=baskets.at(j))&&(basketindex[j]==0)){
                    basketindex[j]=1;
                    fruit.push_back(i);
                    break;
                }

            }
        }
        return (fruits.size()-fruit.size());
    }
};