class Solution {
public:
    #include<deque>
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        deque<int>q;
        int l=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(q.size()<k){
                int n=q.size();
                while(n--){
                    if(nums[q.front()]==nums[i]){
                        q.pop_front();
                    }
                    else{
                        q.push_back(q.front());
                        q.pop_front();
                    }
                }
                q.push_back(i);
                if(q.size() == k){
                    ans += q.front() - l + 1;
                }
            }
            else{
                int flag=0;
                int n=q.size();
                while(n--){
                    if(nums[q.front()]==nums[i]){
                        flag=1;
                        q.pop_front();
                    }
                    else{
                        q.push_back(q.front());
                        q.pop_front();
                    }
                }
                if(flag){
                    q.push_back(i);
                    ans+=q.front()-l+1;
                }
                else{
                    l=q.front()+1;
                    q.pop_front();
                    q.push_back(i);
                    ans += q.front() - l + 1;
                }
            }
        }
        return ans;
    }
};