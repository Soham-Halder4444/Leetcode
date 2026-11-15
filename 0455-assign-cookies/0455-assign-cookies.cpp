class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int j=0;
        for(int i=0;i<g.size();i++){
            int flag=0;
            while(1){
                if(j>=s.size()){
                    flag=1;
                    break;
                }
                else{
                    if(s[j]<g[i]){
                        j++;
                    }
                    else{
                        ans++;
                        j++;
                        break;
                    }
                }
                
            }
            if(flag){
                return ans;
            }
        }
        return ans;
    }
};