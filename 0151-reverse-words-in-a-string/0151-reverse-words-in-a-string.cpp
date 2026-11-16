class Solution {
public:
    #include<stack>
    string reverseWords(string s) {
        stack<char>st1;
        stack<char>st2;
        string ans="";
        for(char ch:s){
            if(ch !=' '){
                st1.push(ch);
            }
            else{
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
                st2.push(ch);
            }
        }
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        while(!st2.empty() && st2.top() == ' '){
            st2.pop();
        }
        while(!st2.empty()){
            if(!ans.empty() && ans.back()==' ' && st2.top()==' '){
                st2.pop();
                continue;
            }
            ans=ans+st2.top();
            st2.pop();
        }
        if(ans.back()== ' '){
            ans.pop_back();
        }
        return ans;
    }
};