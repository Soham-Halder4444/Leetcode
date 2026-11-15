class Solution {
public:
    int solve2(vector<int>& nums2,stack<int>& s, int i,int maxi){
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        if (s.empty())
            return INT_MIN;

        return s.top();
    }
    int solve1(vector<int>& nums2, stack<int>& s, int i) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }

        if (s.empty())
            return INT_MIN;

        return s.top();
    }
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s1;
        stack<int>s2;
        vector<int>next(nums.size());
        for(int i=nums.size()-2;i>=0;i--){
            s1.push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            int val=solve1(nums,s2,i);
            s2.push(nums[i]);
            if(val==INT_MIN){
                val=solve2(nums,s1,i,INT_MIN);
            }
            if(val==INT_MIN){
                next[i]=-1;
            }
            else{
                next[i]=val;
            }
        }
        return next;
    }
};