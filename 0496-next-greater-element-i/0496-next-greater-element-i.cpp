class Solution {
public:
    int solve(vector<int>& nums2, stack<int>& s, int i) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }

        if (s.empty())
            return -1;

        return s.top();
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        stack<int>s;
        int n=nums2.size();
        vector<int>next(n);
        vector<int>ans;
        for(int i=nums2.size()-1;i>=0;i--){
            next[i]=solve(nums2,s,i);
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(next[j]);
                    break;
                }
            }
        }
        return ans;
        /*int n=nums2.size();
        int m=nums1.size();
        vector<int>next(n);
        vector<int>ans;
        next[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            int flag=0;
            for(int j=i+1;j<n;j++){
                if(nums2[i]<nums2[j]){
                    next[i]=nums2[j];
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                next[i]=-1;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(next[j]);
                    break;
                }
            }
        }
        return ans;*/
    }
};