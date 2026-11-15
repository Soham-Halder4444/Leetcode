class Solution {
public:
    #include <deque>
    int totalFruit(vector<int>& fruits) {
        deque<int>q;
        int maxi=0;
        int l=0;
        int r=0;
        for(int i=0;i<fruits.size();i++){
            if(q.size()<2){
                if(q.size()==0){
                    q.push_back(i);
                }
                else{
                    if(fruits[q.front()]==fruits[i]){  
                        q.pop_back();
                        q.push_back(i);
                    }
                    else{
                        q.push_back(i);
                    }
                }
                maxi=r-l+1;
                r++;
            }
            else{
                if(fruits[i]==fruits[q.front()]){
                    q.pop_front();
                    q.push_back(i);
                    maxi=max(maxi,r-l+1);
                    r++;
                }
                else if(fruits[i]==fruits[q.back()]){
                    q.pop_back();
                    q.push_back(i);
                    maxi=max(maxi,r-l+1);
                    r++;
                }
                else{
                    l=q.front()+1;
                    q.pop_front();
                    q.push_back(i);
                    maxi=max(maxi,r-l+1);
                    r++;
                }
            }
        }
        return maxi;
    }
};