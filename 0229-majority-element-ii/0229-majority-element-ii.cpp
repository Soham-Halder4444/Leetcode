class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        int n = nums.size();

        int cnt1 = 0, cnt2 = 0;
        // int e1 = nums[0]
        int e1, e2;
        for(int i = 0; i < n; i++){
            if(nums[i] == e1) cnt1++;
            else if(nums[i] == e2) cnt2++;

            else if(cnt1 == 0){
                e1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                e2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        // cout<<e1<<" "<<e2;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(e1 == nums[i]) cnt1++;
            if(e2 == nums[i]) cnt2++;
        }
        // cout<<endl<<cnt1<<" "<<cnt2;
        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(e1);
        if(cnt2 > n/3) ans.push_back(e2);

        return ans;
        
    }
};