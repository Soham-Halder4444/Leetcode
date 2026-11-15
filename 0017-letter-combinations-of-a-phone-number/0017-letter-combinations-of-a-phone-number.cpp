class Solution {
public:
    void solve(vector<string>com,int i,string output,vector<string>&ans,string digits){
        if(i==digits.size()){
            ans.push_back(output);
            return;
        }
        for(int j=0;j<com[digits[i]-'0'-2].size();j++){
            output.push_back(com[digits[i]-'0'-2][j]);
            solve(com,i+1,output,ans,digits);
            output.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>com={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string output;
        if(digits.size()==0){
            return ans;
        }
        solve(com,0,output,ans,digits);
        return ans;
    }
};