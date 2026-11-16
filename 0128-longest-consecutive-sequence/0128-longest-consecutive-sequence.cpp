class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int cnt=0;
        int e;
        auto it=m.begin();
        if(it!=m.end()){
            e=it->first;
            ++it;
            cnt++;
        }
        int result=cnt;
        for (; it != m.end(); ++it) {
            if(it->first-e==1){
                cnt++;
                e=it->first;
            }
            else{
                cnt=1;
                e=it->first;
            }
            result=max(result,cnt);
        }
        return result;;
    }
};