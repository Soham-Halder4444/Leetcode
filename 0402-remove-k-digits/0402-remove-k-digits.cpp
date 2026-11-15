class Solution {
public:
    void solve(stack<int>&s,int x,int &n){
        if(s.empty() || n==0 || s.top()<=x){
            return;
        }
        s.pop();
        n--;
        solve(s,x,n);
    }
    string removeKdigits(string num, int k) {
        if(k>=num.size()){
            return "0";
        }
        stack<int>s;
        stack<int>s2;
        int n=k;
        for(int i=0;i<num.size();i++){
            int x=num[i]-'0';
            if(s.empty()){
                s.push(x);
                continue;
            }
            if(x>=s.top()){
                s.push(x);
            }
            else{
                if(n != 0){
                    solve(s, x, n);
                }
                s.push(x);
            }
        }
        if(n!=0){
            while(n && !s.empty()){
                n--;
                s.pop();
            }
        }
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty() && s2.top()==0){
            s2.pop();
        }
        string ans;
        if(s2.size()==0){
            return "0";
        }
        while(!s2.empty()){
            ans.push_back(s2.top()+'0');
            s2.pop();
        }
        return ans;
    }
};