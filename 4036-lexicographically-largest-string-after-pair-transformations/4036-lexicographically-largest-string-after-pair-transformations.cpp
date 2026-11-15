class Solution {
public:
    #include<cmath>
    int power(int val){
        int i=1;
        while(1){
            if(i>25){
                return 25;
            }
            if(pow(2,i)<=val){
                i++;
            }
            else{
                break;
            }
        }
        return i-1;
    }
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            string a="";
            if(nums[i]==1){
               a.push_back('a');
                ans.push_back(a);
                continue;
            }
            int val=nums[i];
            while(val>=2){
                int x=power(val);
                val=val-(pow(2,x));
                a.push_back('a'+x);
                if(val==1){
                    a.push_back('a');
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};